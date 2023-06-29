def calculaCustoConsumidor(custoFabrica):
    pd = custoFabrica * 0.28
    impostos = custoFabrica * 0.45

    custoConsumidor = custoFabrica + pd + impostos
    return custoConsumidor


