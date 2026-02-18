echo "Testando (42 comandos)..."
echo

output=$(./a.out < ./testes/input2.txt)
expected_output="Lista: 5 15 25 35 45
Elemento 25 encontrado na posição 3.
Elemento 50 não encontrado.
Lista: 5 10 15 25 35 45
Lista: 5 10 15 20 25 35 45
Lista: 5 10 20 25 35 45
Lista: 5 10 20 25 35
Lista: 5 10 25 35
Lista: 10 25 35
Elemento 5 não encontrado.
Elemento 100 não encontrado.
Tamanho da lista: 3
Lista: 10 30 25 35
Lista: 10 30 40 25 35
Lista: 10 30 40 50 25 35
Lista: 10 30 40 50 60 25 35
Lista: 10 30 40 50 60 25 35
Lista: 10 40 50 60 25 35
Lista: 10 40 50 25 35
Elemento 40 encontrado na posição 2.
Elemento 60 não encontrado.
Tamanho da lista: 5
Lista vazia.
Lista: 99 77 66 55 88
Elemento 99 encontrado na posição 1.
Elemento 88 encontrado na posição 5.
Elemento 77 encontrado na posição 2.
Elemento 66 encontrado na posição 3.
Elemento 55 encontrado na posição 4.
Lista: 99 66 55 88
Lista: 99 66 88
Lista: 99 88
Lista: 88
Elemento 88 encontrado na posição 1.
Tamanho da lista: 1
Lista vazia."


if [ $? -eq 0 ] ; then
  echo "Running ok: Program exited zero"
else
  echo "Fail on running: Program did not exit zero"
  exit 1
fi

if [ "$output" == "$expected_output" ] ; then
  echo "Pass: A saida esperada esta correta"
else
  echo "Era esperado '$expected_output' mas o programa retornou: $output"
  exit 1
fi

echo
echo "Teste 2 realizado com sucesso"

exit 0