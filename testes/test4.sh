echo "Testando (remocao de numeros repetidos)..."
echo

output=$(./a.out < ./testes/input4.txt)
expected_output="Lista: 10 20 30 10 40 10 50
Lista: 20 30 40 50
Elemento 10 não encontrado.
Elemento 20 encontrado na posição 1.
Elemento 30 encontrado na posição 2.
Elemento 40 encontrado na posição 3.
Elemento 50 encontrado na posição 4.
Tamanho da lista: 4
Lista: 20 30 40 50."


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
echo "Teste 4 realizado com sucesso"

exit 0