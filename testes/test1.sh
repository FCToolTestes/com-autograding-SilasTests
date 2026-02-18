echo "Testando (exemplo incial)..."
echo

output=$(./a.out < ./testes/input1.txt)
expected_output="Lista: 10 20 30
Elemento 20 encontrado na posição 2.
Lista: 10 20 25 30
Lista: 20 25 30
Lista: 20 30
Tamanho da lista: 2
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
echo "Teste 1 realizado com sucesso"

exit 0