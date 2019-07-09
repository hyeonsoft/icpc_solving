for (int a = 1; a <= N; a++) {
	for (int b = 1; b <= N; b++) {
		if (a == b)continue;
		map[a][b] = INF;
	}
}
for (int k = 1; k<=N; k++) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
		}
	}
}