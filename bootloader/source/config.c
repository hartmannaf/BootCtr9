#include "config.h"


int myAtoi(const char *str)
{
    int res = 0; // Initialize result
  	int startvalue = 0;
    // Iterate through all characters of input string and
    // update result
    bool isnegativ=false;
    if(str[0]=='-')
    {
    	isnegativ=true;
    	startvalue=1;
    }
    for (int i = startvalue; str[i] != '\0'; ++i)
        res = res*10 + str[i] - '0';
  
  	if(isnegativ)
  		res*=-1;
    // return result.
    return res;
}
int chartoint(int c)
{
    char hex[] = "aAbBcCdDeEfF";
    int i;
    int result = 0;

    for(i = 0; result == 0 && hex[i] != '\0'; i++)
    {
        if(hex[i] == c)
        {
            result = 10 + (i / 2);
        }
    }

    return result;
}

unsigned int htoi(const char s[])
{
    unsigned int result = 0;
    int i = 0;
    int proper = 1;
    int temp;

    //To take care of 0x and 0X added before the hex no.
    if(s[i] == '0')
    {
        ++i;
        if(s[i] == 'x' || s[i] == 'X')
        {
            ++i;
        }
    }

    while(proper && s[i] != '\0')
    {
        result = result * 16;
        if(s[i] >= '0' && s[i] <= '9')
        {
            result = result + (s[i] - '0');
        }
        else
        {
            temp = chartoint(s[i]);
            if(temp == 0)
            {
                proper = 0;
            }
            else
            {
                result = result + temp;
            }
        }

        ++i;
    }
    //If any character is not a proper hex no. ,  return 0
    if(!proper)
    {
        result = 0;
    }

    return result;
}

int numberToInt(const char* value)
{
	if(value[0]=='0'&& (value[1]=='x'||value[1]=='X'))
		return htoi(value);
	else
		return myAtoi(value);
}

int handler(void *user, const char *section, const char *name, const char *value)
{
	configuration *pconfig = (configuration *) user;
	if (MATCH(pconfig->section, "path")) {
		strcpy (pconfig->path,value);
	} else if (MATCH(pconfig->section, "delay")) {
		pconfig->delay = myAtoi(value);
	} else if (MATCH(pconfig->section, "payload")) {
		pconfig->payload = myAtoi(value);
	} else if (MATCH(pconfig->section, "offset")) {
		pconfig->offset = numberToInt(value);
	}
	return 1;
}