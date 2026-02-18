echo "Testando (6)..."
echo

# Teste de uso do malloc
if grep -E '^[^/]*\bfree\b' ./listaEncadeada.c; then
  echo "Pass: A função free foi usada no código"
else
  echo "Fail: A função free não foi encontrada no código"
  exit 1
fi

echo
echo "Teste 6 realizado com sucesso"

exit 0
