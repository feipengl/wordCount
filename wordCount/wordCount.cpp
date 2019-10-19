int CalculateWords(char *p)
{
	int len = strlen(p), j=0, i=0,counts=0;
	/*大写字母转成小写字母*/ 
	for(i=0;i<len;i++)
	{
		if(p[i]>='A'&&p[i]<='Z')
		p[i]=p[i]+32;
	}
	i=0;
	for(j=i+1;j<len;j++)
	{
		if(p[j]<'0' || p[j]>'z'||p[j]>'9'&&p[j]<'a')
		continue;   //如果是非字母数字字符则继续遍历 
		else
		{
			int flag=0;  //记录前四个是否为字母 
			for(i=j;i<len;i++)
			{
				if(p[i]>='a' && p[i]<='z')
				{
					flag++;
					continue;
				}
					
				if((p[i]<'a' || p[i]>'z')&&flag<4)
					break;  //如果不是四个连续字母则退出循环 
				if(flag>3&&(p[i]<'0' || p[i]>'z'||(p[i]>'9'&&p[i]<'a')))
				{
					counts++;
					break;
				}
			}
		}
		if(j== len-1)
			return counts;
	}
}
