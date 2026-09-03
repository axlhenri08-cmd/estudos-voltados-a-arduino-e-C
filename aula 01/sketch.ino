// Bibliotecas
#include <Wire.h>
/*Ela implementa o protocolo I2C: o "idioma" que a ESP32 usa
  para conversar com o modulo do LCD usando so 2 fios (SDA e SCL).*/

#include <LiquidCrystal.h>
// Biblioteca externa
/*Ela consegue traduzir texto simples como lcd.print("Ola")
  para os sinais eletricos que o controlador do LCD entende.*/

// COnfiguração de objetos, nesse caso o LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);
// Isso é um "obijeto" chamado de lcd, que serve para representar a tela fisica.
// Foram usados 3 parametros, sendo eles:
// -0x27 -> este é o endereço I2C do modulo (o mais comum; caso não fincinar, também tem outro, no caso o 0x3F)
// -16 -> esse é o numero de colunas (caracteres por linhas) do seu LCD.
// -2 -> numero de linhas do LCD usado agora.
// OBS: caso o lcd seja maior, como o (20x4), altere para lcd(0x27, 20, 4).

// Construção do setup(roda apenas uma vez) quando a ESP32 ligar.

void setup() {
  Wire.begin(1, 2);
  /* Com essa função, explicamos explicitamente ao ESP32 quais pinos fisicos ou virtuais
     correspondem a SDA e SCL, na ordem: Wiew.begin(SDA, SCL).
     Nesse diagrama o SDA esta conectado no GPIO1 e o SCL no GPIO2, que corresponde a
     Wire.begin(1, 2).*/

  lcd.init();
  // Ativa o controlador do LCD e prepara ele para receber comandos.

  lcd.backlight();
  // Liga a luz de fundo do LCD (sem essa função a tela ficara escura) e
  // não dara para ver o texto, mesmo ele estando lá.

  lcd.setCursor(0, 0);
  // Posiciona o "cursor" (onde o proximo texto sera escrito).
  // o primeiro numero é a coluna (0 = primeira coluna), o segundo é a linha (0 = primeira linha).

  lcd.print("Galpão avicola");
  // Escreve o texto a partir da posição do cursor definida acima.

  lcd.setCursor(0, 1);
  // move o cursor para a coluna 0, linha 1 (nesse caso a segunda linha do LCD).

  lcd.print("Sistemas Ok!");
  // escreve o texto na segunda linha.
}

// Futura construção com o loop(roda para sempre, em repetição).

void loop() {
  // Por enquanto, deixamos vazio de propósito.
  // Como a mensagem já foi escrita uma única vez dentro do setup(),
  // ela permanece fixa na tela — não precisamos repetir o comando aqui.
  // Mais para frente, quando conectarmos sensores de verdade,
  // é AQUI dentro que vamos atualizar o texto com os valores lidos.
}