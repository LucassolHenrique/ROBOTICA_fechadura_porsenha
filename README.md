# Sistema de Trava Automatizada com Arduino 🔐

Este projeto implementa um **sistema de trava automatizada** utilizando um **Arduino** 🖥️, um **teclado matricial** (Keypad) ⌨️ e um **servo motor** 🤖. O sistema permite que a trava seja acionada com base em uma senha configurada, com feedback visual através de LEDs 💡.

## Funcionalidades ✨

- **Entrada de senha**: A senha é inserida por meio de um teclado matricial 4x3.
- **Verificação de senha**: Se a senha estiver correta, o sistema libera a trava 🔓. Caso contrário, indica erro ❌.
- **Feedback visual com LEDs**: 
  - LED **vermelho**: Indicando erro 🚫.
  - LED **verde**: Indicando sucesso ✅ (senha correta).
  - LED **amarelo**: Indicando que a senha está sendo digitada ✍️.
- **Controle de servo motor**: Após a validação da senha, o servo motor gira, liberando ou travando a fechadura 🔒.

## Componentes Utilizados 🧰

- **Arduino Uno** ou qualquer placa compatível 🖥️.
- **Teclado matricial 4x3** ⌨️.
- **Servo motor** 🤖.
- **3 LEDs** (vermelho, verde e amarelo) 💡.
- **Resistores** e **fios de conexão** 🔌.

## Instalação 🛠️

1. Clone este repositório ou baixe os arquivos 📥.
2. Conecte os componentes conforme o diagrama de circuito fornecido 🔧.
3. Faça o upload do código para o Arduino 📤.
4. Utilize o monitor serial para ver as interações do código e acompanhar o movimento do servo 🔄.

## Como Funciona 🔄

1. O código solicita que o usuário insira a senha utilizando o teclado matricial ⌨️.
2. Quando o usuário pressionar o `#`, o código verifica se a senha está correta ✅.
3. Se a senha for correta, o LED verde acende ✅ e o servo motor gira para liberar a fechadura 🔓.
4. Se a senha estiver errada, o LED vermelho acende 🚫.
5. Durante a digitação, o LED amarelo fica aceso ✍️.

### Como o código funciona 📝

- **Teclado Matricial**: O teclado de 4x3 permite ao usuário inserir números e comandos. A senha é verificada ao pressionar o `#` 🔢.
- **Servo Motor**: Quando a senha é correta, o servo motor é acionado para mover a fechadura, liberando o acesso 🔓.
- **LEDs**: LEDs indicam o status da operação. O LED verde acende quando a senha é correta ✅, enquanto o LED vermelho acende quando a senha é incorreta 🚫.

### Funções principais ⚙️

- **`verificaSenha()`**: Compara a senha digitada com a senha armazenada no sistema. Retorna `true` se as senhas coincidirem, caso contrário, retorna `false`.
- **`leds()`**: Controla os LEDs, acendendo-os conforme o estado atual (aguardando, digitando, senha incorreta, senha correta) 💡.
- **`setup()`**: Inicializa o hardware necessário (teclado, LEDs, servo) e configura as portas ⚙️.
- **`loop()`**: Executa o código repetidamente, aguardando entradas do teclado e acionando as funções de verificação e controle de LEDs 🔄.

### Bibliotecas Utilizadas 📚

- **Keypad**: Para ler as teclas pressionadas no teclado matricial ⌨️.
- **Servo**: Para controlar o servo motor que movimenta a fechadura 🤖.

## Código 💻

O código é escrito em **C** para Arduino e utiliza as bibliotecas:


