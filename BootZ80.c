#include <stdio.h>

void SetRTS(void)
{
  printf("RTS=1\n");
}

void ClearRTS(void)
{
  printf("RTS=0\n");
}

void SendByte(unsigned char b)
{
  printf("RESET (TxD pulse low)\n");
}

void SetAtHLIncHL(void)
{
  SetRTS();
  SendByte(0);
  ClearRTS();
  SendByte(0);
}

void IncAtHLIncHL(void)
{
  ClearRTS();


#include <stdio.h>

void SetRTS(void)
{
  printf("RTS=1\n");
}

void ClearRTS(void)
{
  printf("RTS=0\n");
}

void SendByte(unsigned char b)
{
  printf("RESET (TxD pulse low)\n");
}

void SetAtHLIncHL(void)
{
  SetRTS();
  SendByte(0);
  ClearRTS();
  SendByte(0);
}

void IncAtHLIncHL(void)
{
  ClearRTS();
  SendByte(0);
}


void SetMem(unsigned char *m, int n)
{
  unsigned char l=0;

  for(int i=0; i<n; i++)
  {
    m[i]=(m[i]+0xDC) & 0xFF;

    if (m[i] > l)
      l = m[i];

    SetAtHLIncHL();
  }

  for(;l>0;l--)
  {
    printf("Iteration l=%d\n",(int)l);
    for(int i=0; i<n; i++)
    {
      if (m[i]<l)
        SetAtHLIncHL();
      else
        IncAtHLIncHL();
    }
  }
}

int main() {
  unsigned char m[16];
  
  for(int i=0; i<16; i++)
  {
    m[i]=0x2b;
  }
  
  m[15]=0x76;

  SetMem(m,16);
  
  return 0;
}
