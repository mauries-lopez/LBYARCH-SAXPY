///
/// <summary>
/// This is Single precision (A*X) + Y.
/// This will multiply <paramref name="A" /> to <paramref name="x" /> and add that to <paramref name="y" /> and store that value to <paramref name="z" />.
/// </summary>
/// <param name="A">is the scalar value</param>
/// <param name="x">is the vector x</param>
/// <param name="y">is the vector y</param>
/// <param name="z">holds the output of the computation. It is vector z.</param>
/// <returns>Nothing</returns>
void computeSAXPY(int A, int n, float* x, float* y, float* z) {
	int i;
	for (i = 0; i <= n; i++) 
		*(z + i) = (A * *(x + i)) + *(y + i);
}