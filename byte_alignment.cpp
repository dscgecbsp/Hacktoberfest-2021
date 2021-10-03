Byte alignment in a struct

#include <iostream.h>

#define ALIGN 8
#pragma pack(ALIGN)

/* Algorithm

Byte offset between currentType and nextType  = MIN( multiple of Byte
Alignment specified , multiple of size of nextType)
**/

int ALIGNOFFSET(int currRelativeAddess,int currrentTypeSize,int
nextTypeSize)
{

	int nOffset = currrentTypeSize ;//this is size of the current
type.Offset will be minimum of this size.
	currRelativeAddess += currrentTypeSize ; //cuurent address is
increased by size of current type.
	if( nextTypeSize < ALIGN) // now alignment depens on the next type
and also alignment defined by #pragam pack(#)
	{
		// if the size of next type is less than byte alignment size
specified , then offset will be increased to the muliple of
		// size of next type.
		int nRemainder  = currRelativeAddess % nextTypeSize ;
		if(nRemainder != 0)
		{
			nOffset += nextTypeSize - nRemainder ;//this will
align boundary to next multiple of nextTypeSize
		}

	}
	else
	{
		// if the byte alignment size specified is less than size of
next type , then offset will be increased to the next muliple of
		// size of byte alignment.
		int nRemainder  = currRelativeAddess % ALIGN ;
		if(nRemainder != 0)
		{
			nOffset += ALIGN - nRemainder ;//this will align the
boundary to next multiple of ALIGN
		}
	}
	return nOffset ;
}


struct S
{

   char a[2];
   int b;
   double c;
   char d[1];
   int e;
   double f;
};

void main()
{
	S sz;
	cout << "size of struct :" << sizeof(sz) << endl;
	cout << "address of size::a "<< &sz.a <<" Actual offset = " <<
int(0) << " Calculated offset = " << 0 << endl;

	int offset = ((int)&sz.b)- (int)(&sz.a);


	cout << "address of size::b " << &sz.b <<" Actual offset = " <<
offset << " Calculated offset = " << ALIGNOFFSET((int)(&sz.a)-
(int)(&sz),sizeof(sz.a),sizeof(sz.b)) << endl;
	offset = ((int)&sz.c)- (int)(&sz.b);

	cout << "address of size::c " << &sz.c <<" Actual offset = " <<
offset << " Calculated offset = " << ALIGNOFFSET((int)(&sz.b) -
(int)(&sz),sizeof(sz.b),sizeof(sz.c)) << endl;
	offset = ((int)&sz.d)- (int)(&sz.c);

	cout << "address of size::d " << &sz.d <<" Actual offset = " <<
offset << " Calculated offset = " << ALIGNOFFSET((int)(&sz.c)-
(int)(&sz),sizeof(sz.c),sizeof(sz.d)) << endl;

	offset = ((int)&sz.e)- (int)(&sz.d);

	cout << "address of size::e " << &sz.e <<" Actual offset = " <<
offset << " Calculated offset = " << ALIGNOFFSET((int)(&sz.d)-
(int)(&sz),sizeof(sz.d),sizeof(sz.e)) << endl;
	offset = ((int)&sz.f)- (int)(&sz.e);
	cout << "address of size::f " << &sz.f <<" Actual offset = " <<
offset << " Calculated offset = " << ALIGNOFFSET((int)(&sz.e)-
(int)(&sz),sizeof(sz.e),sizeof(sz.f)) << endl;
}
