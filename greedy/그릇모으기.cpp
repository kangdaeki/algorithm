#include <stdio.h>

int T = 0;
int N = 0;
int chunks[51][51];
int hs[51];
int indices[51];

int first_index()
{
	int f = -1;
	for (int i = 0; i < N; i++) {
		if (indices[i] >= hs[i]) continue;
		if (-1 == f) f = i;
		else if (chunks[i][indices[i]]<chunks[f][indices[f]]) f = i;
	}
	return f;
}

int main()
{
	scanf("%d",&T);
	for (int t = 0; t < T; t++) {
		scanf("%d", &N);
		if (1 >= N) {
			printf("%d\n", N);
			return 0;
		}
		for (int i = 0; i < N; i++) {
			scanf("%d", &hs[i]);
			for (int j = 0; j < hs[i]; j++) scanf("%d", &chunks[i][j]);
		}
		printf("Case #%d\n", t + 1);
		int count = 0;
		int first = first_index();
		while (-1 != first) {
			indices[first]++;
			int next = first_index();
			if (-1 == next) break;
			if (next != first) {
				if (indices[first] < hs[first]) count++;
				count++;
				first = next;
			}
		}

		printf("%d\n", count);
	}
	return 0;
}
