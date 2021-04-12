int countMatches(char *** items, int itemsSize, int* itemsColSize, char * ruleKey, char * ruleValue) {
	char *key[3] = { "type","color","name" };
	int count = 0;
	for (int i = 0; i < 3; i++)
	{
		if (!strcmp(ruleKey, key[i]))
		{
			for (int j = 0; j < itemsSize; j++)
				if (!strcmp(ruleValue, items[j][i]))
					count++;
		}
	}
	return count;
}
//