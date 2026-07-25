# Time Complexity Analysis - Practical 03

- **Build Max-Heap**: \(\mathcal{O}(n)\) proof:
  \[ \sum_{h=0}^{\lfloor \log n \rfloor} \frac{n}{2^{h+1}} \mathcal{O}(h) = \mathcal{O}\left(n \sum_{h=0}^{\infty} \frac{h}{2^h}\right) = \mathcal{O}(2n) = \mathcal{O}(n) \]
- **n - 1 Heapify Extractions**: \((n - 1) \times \mathcal{O}(\log n) = \mathcal{O}(n \log n)\).
- **Total Time Complexity**: \(\mathcal{O}(n \log n)\) across all cases (Best, Average, Worst).
