# Advantages & Limitations - Practical 03

## Advantages
- Guaranteed worst-case \(\mathcal{O}(n \log n)\) runtime.
- Operates in-place with \(\mathcal{O}(1)\) auxiliary memory.

## Limitations
- **Unstable Sort**: Does not preserve relative input order for duplicate keys.
- **Poor Cache Locality**: Array index jumps (`2i + 1`) lead to cache misses compared to Quick Sort.
