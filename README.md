## Baixar as dependências e rodar o código

Para o openMP:

Verifique se o GCC está instalado digitando o seguinte comando:
```
gcc --version
```
Se o GCC não estiver instalado, você pode instalá-lo usando o gerenciador de pacotes do seu sistema. Por exemplo, no Ubuntu e no Debian, você pode usar o comando:
```
sudo apt-get install build-essential
```
Após verificar que o GCC está instalado, você pode compilar seu código-fonte com suporte ao OpenMP usando a opção de linha de comando -fopenmp. Por exemplo:
```
gcc -fopenmp seu_arquivo.c -o seu_programa
```

Certifique-se de substituir "seu_arquivo.c" pelo nome do seu arquivo de código-fonte e "seu_programa" pelo nome que você deseja dar ao executável resultante.

Para o openMPI:

Verifique se o gerenciador de pacotes do seu sistema está atualizado executando o seguinte comando:
```
sudo apt update
```
Em seguida, instale as dependências necessárias para compilar o OpenMPI executando o seguinte comando:
```
sudo apt install build-essential
```
Agora, você pode instalar o pacote OpenMPI digitando o seguinte comando:
```
sudo apt install openmpi-bin
```

# Dataset utilizado

```
https://www.kaggle.com/code/jorgebuenoperez/map-of-railway-connections/input
```
