#include "pch.h"
#include "Header.h"
#include "Header1.h"
#include <iostream>
#include "fstream"
#include <string>

int main()
{
	srand(time(NULL));
	
	
	
	//massiv W(6);
	//cout << endl;
	//ofstream ofs("File1003.bin", ios::binary);
	//if (!ofs)
	//{
	//	cout << "error1" << endl;
	//	return 1;
	//}
	//ofstream out("File1003.txt");
	//W.writefile(ofs, out, "File1003.bin");
	//ofs.close();
	//out.close();

	//massiv Z(5);
	////Z.create(5);
	//ifstream infile("File1003.bin", ios::binary);
	//ifstream in("File1003.txt");
	//if (!infile)
	//{
	//	cout << "error2" << endl;
	//	return 2;
	//}
	//cout << "Zagruzhenniy massiv: " << endl;
	//Z.readfile(infile, in);
	//infile.close();
	//in.close();
	//Z.Print();
	//cout << endl;
	//cout << endl;
	
	/*massiv W(6);
	cout << endl;
	ofstream ofs("File1003.bin", ios::binary);
	if (!ofs)
	{
		cout << "error1" << endl;
		return 1;
	}
	ofstream out("File1003.txt");
	W.writefile(ofs, out, "File1003.bin");
	ofs.close();
	out.close();*/
	
	/*cout << "Sohranenniy massiv: " << endl;
	W.Print();
	cout << endl;
	ofs.close();*/





	bicycle *x; car q;
	taxi b; bus d; 
	List a; a.Add(&q);
	a.Add(&b); a.Add(&d);

	a.Show();
	a.create(5); cout << endl << endl; a.Show();

	system("pause");
}