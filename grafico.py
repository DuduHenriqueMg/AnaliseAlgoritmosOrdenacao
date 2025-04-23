import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv('tempos.csv', sep=',')

pivot = df.pivot(index='N', columns='Algoritmo', values='Tempo')

plt.figure(figsize=(8,5))

for alg in pivot.columns:
    plt.plot(pivot.index, pivot[alg], marker='o', label=alg)

# Escalas: X linear (padrão) e Y log
plt.yscale('log')

plt.xlabel('Tamanho do vetor (N)')
plt.ylabel('Tempo (ms) Escala logarítmica')
plt.title('Comparação de tempos de ordenação')
plt.legend()
plt.grid(axis='y', which='major', ls='--', alpha=0.5)
plt.tight_layout()
plt.show()