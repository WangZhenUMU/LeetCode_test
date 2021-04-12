int subtractProductAndSum(int n) {
	int t = n;
	int sum = 0, pro = 1;
	while (t)
	{
		sum += t % 10;
		pro *= t % 10;
		t /= 10;
	}
	return pro - sum;
}