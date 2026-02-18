echo "Testando (alocação)..."
echo

# Teste de uso do malloc
if grep -E '^[^/]*\bmalloc\b' ./listaEncadeada.c; then
  echo "Pass: A função malloc foi usada no código"
else
  echo "Fail: A função malloc não foi encontrada no código"
  exit 1
fi

echo
echo "Teste 5 realizado com sucesso"

exit 0
