char * interpret(char * command) {
	int count = 0;
	int len = strlen(command);
	char* str = malloc(sizeof(char)*(len + 1));
	int i = 0;
	while (count < len)
	{
		if (command[count] == 'G')
		{
			str[i++] = 'G';
			count++;
		}
		else
		{
			count++;
			if (command[count] == 'a')
			{
				str[i++] = 'a';
				str[i++] = 'l';
				count += 3;
			}
			else
			{
				str[i++] = 'o';
				count++;
			}
		}
	}
	str[i] = '\0';
	return str;
}