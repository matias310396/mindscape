# Sonic

### Gênero

Plataforma.

### Descrição

Jogo individual da disciplina de Introdução à Jogos Eletrônicos. Trata-se de uma versão de Sonic, com moedas coletáveis e espinhos no cenário que te derrotam ao toque.

### Instruções

* Andar para frente: →  
* Andar para trás: ← 
* Pular:  ↑

### Envolvidos

| Nome | Matrícula |
| :--: | :-----: |
| Victor Navarro | 14/0032932 |

### Dependências

As dependências estão listadas pelo nome do pacote. Dessa forma, em distribuições _linux_ baseadas em _Debian_, é necessário apenas rodar "sudo apt-get install nomeDoPacote".
* libsdl2-dev

### Compilando e Executando

Após clonar o repositório, entre na pasta Sonic. Nesse diretório, há um _script_ sh responsável pela interação com o CMake e, portanto, com a compilação e execução. Dentro da pasta, os comandos e suas funções são:

| Comando | Efeito |
| :----:  | :----: |
| `./control.sh build` | Gera os novos _Makefiles_ |
| `./control.sh make` | Usa os _Makefiles_ gerados para compilar o jogo |
| `./control.sh run` | Executa o jogo |

