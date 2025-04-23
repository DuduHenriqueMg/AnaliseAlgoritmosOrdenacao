import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv('tempos.csv', sep=',')

pivot = df.pivot(index='N', columns='Algoritmo', values='Tempo')
fig, axes = plt.subplots(1, 3, figsize=(20, 8))

# --- Gráfico 1: Barras  ---
pivot.plot(kind='bar', ax=axes[0])
axes[0].set_title('Comparação de Desempenho - Barras')
axes[0].set_xlabel('Tamanho do vetor (N)')
axes[0].set_ylabel('Tempo (ms)')

# --- Gráfico 1: Barras com escala logarítmica ---
pivot.plot(kind='bar', ax=axes[1])
axes[1].set_yscale('log')
axes[1].set_title('Comparação de Desempenho - Barras (Escala Log)')
axes[1].set_xlabel('Tamanho do vetor (N)')
axes[1].set_ylabel('Tempo (ms)')

# --- Gráfico 2: Linhas com escala logarítmica ---
for alg in pivot.columns:
    axes[2].plot(pivot.index, pivot[alg], marker='o', label=alg)

axes[2].set_yscale('log')
axes[2].set_title('Comparação de Desempenho - Linhas (Escala Log)')
axes[2].set_xlabel('Tamanho do vetor (N)')
axes[2].set_ylabel('Tempo (ms)')
axes[2].legend()
axes[2].grid(axis='y', which='major', linestyle='--', alpha=0.5)
