char * defangIPaddr(char * address) {
	char *addressw = malloc(strlen(address) + 7);
	int i = 0, j = 0;
	while (address[i])
	{
		if (address[i] == '.')
		{
			addressw[j++] = '[';
			addressw[j++] = '.';
			addressw[j++] = ']';
		}
		else
			addressw[j++] = address[i];
		i++;
	}
	addressw[j] = '\0';
	return addressw;
}