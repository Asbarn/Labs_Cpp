#pragma once
#include "iostream"
#include <string>
#include "iomanip"
#include <cstdlib>
#include "vector"
#include "cassert"
#include "fstream"


using namespace std;


class bicycle
{
protected:
	string brand, tvehicle;
	int speed;
public:
	bicycle() {
		tvehicle = "Bicycle";
		int i = (rand() % 5) + 1;
		switch (i)
		{
		case 1:
		{
			brand = "GT";
		}
		break;
		case 2:
		{
			brand = "Trek";
		}
		break;
		case 3:
		{
			brand = "Aist";
		}
		break;
		case 4:
		{
			brand = "Giant ";
		}
		break;
		case 5:
		{
			brand = "KHS";
		}
		break;
		case 6:
		{
			brand = " Merida";
		}
		break;
		default:
		{
			brand = "Kellys";

		}
		}
		speed = (rand() % 15) + 1;
	}
	bicycle(string Brand, string Tvehicle, int Speed) : brand(Brand), tvehicle(Tvehicle), speed(Speed) {}
	void SetTVehicle() { std::getline(std::cin, tvehicle); }
	void SetBrand() { std::getline(std::cin, brand); }
	void SetSpeed() { cin >> speed; }

	string GetTVehicle() { return tvehicle; }
	string GetBrand() { return brand; }
	int GetSpeed() { return speed; }

	void SetInfo() {
		cout << setw(25) << "Enter your brand: "; std::getline(std::cin, brand);
		cout << setw(25) << "Enter your speed: "; cin >> speed;
	}
	virtual void ShowInfo()
	{
		cout << setw(35) << "Info about transport" << endl;
		cout << setw(35) << "Type of vehicle: " << tvehicle << endl;
		cout << setw(35) << "Type of brand: " << brand << endl;
		cout << setw(35) << "Average speed: " << speed << endl;
	}
	 friend ostream &operator <<(ostream&s, bicycle&d)
	{
		s << setw(35) << "Info about transport" << endl;
		s << setw(35) << "Type of vehicle: " << d.tvehicle << endl;
		s << setw(35) << "Type of brand: " << d.brand << endl;
		s << setw(35) << "Average speed: " << d.speed << endl;
		return s;
	}
	 friend istream &operator>>(istream&s, bicycle&d)
	{
		s >> d.tvehicle; s >> d.brand; s >> d.speed;
		return s;
	}

	 virtual void writefile(ofstream &ofs, ofstream &out, bicycle *A)
	 {
		 int a = 0;
		 out << a << endl;
		 ofs.write(reinterpret_cast<char*>(A), sizeof(A));
	 }
	 virtual bicycle* readfile(ifstream &ifs)
	 {
		 ifs.read(reinterpret_cast<char*>(this), sizeof(bicycle));
		 return new bicycle(*this);
	 }
};

class car :public bicycle
{
protected:
	int capacity;
public:
	car()
	{
		tvehicle = "Car";
		int i = (rand() % 8) + 1;
		switch (i)
		{
		case 1:
		{
			brand = "Toyota";
		}
		break;
		case 2:
		{
			brand = "Volkswagen";
		}
		break;
		case 3:
		{
			brand = "Ford";
		}
		break;
		case 4:
		{
			brand = "Mercedes";
		}
		break;
		case 5:
		{
			brand = "Nissan";
		}
		break;
		case 6:
		{
			brand = " Renault";
		}
		break;
		case 7:
		{
			brand = "BMW";
		}
		break;
		case 8:
		{
			brand = "Volvo";
		}
		break;
		case 9:
		{
			brand = "Peugeot";
		}
		break;
		default:
		{
			brand = "Lada";

		}
		}
		speed = 20 + (rand() % static_cast<int>(40 - 20 + 1));//min + (rand() % static_cast<int>(max - min + 1))
		capacity = 40 + (rand() % static_cast<int>(60 - 40 + 1));
	}
	car(string Brand, string Tvehicle, int Speed, int Capacity) : bicycle(Brand, Tvehicle, Speed), capacity(Capacity) {}
	void SetCapacity() { cin >> capacity; }

	int GetCapacity() { return capacity; }

	void SetInfo()
	{
		bicycle::SetInfo();
		cout << setw(25) << "Enter your capacity: "; cin >> capacity;
	}
	void ShowInfo() {
		bicycle::ShowInfo();
		cout << setw(35) << "Average capacity: " << capacity << endl;
	}
	friend ostream &operator <<(ostream&s, car&d)
	{
		s << setw(35) << "Info about transport" << endl;
		s << setw(35) << "Type of vehicle: " << d.tvehicle << endl;
		s << setw(35) << "Type of brand: " << d.brand << endl;
		s << setw(35) << "Average speed: " << d.speed << endl;
		s << setw(35) << "Average capacity: " << d.capacity << endl;
		return s;
	}
	friend istream &operator>>(istream&s, car&d)
	{
		s >> d.tvehicle; s >> d.brand; s >> d.speed; s >> d.capacity;
		return s;
	}

	void writefile(ofstream &ofs, ofstream &out, bicycle *A)
	{
		int a = 1;
		out << a << endl;
		ofs.write(reinterpret_cast<char*>(A), sizeof(car));
	}
	car* readfile(ifstream &ifs)
	{
		ifs.read(reinterpret_cast<char*>(this), sizeof(car));
		return new car(*this);
	}
};

class taxi : public car {
protected:
	int payment;

public:
	taxi()
	{
		tvehicle = "Taxi";
		int i = (rand() % 8) + 1;
		switch (i)
		{
		case 1:
		{
			brand = "Toyota";
		}
		break;
		case 2:
		{
			brand = "Volkswagen";
		}
		break;
		case 3:
		{
			brand = "Ford";
		}
		break;
		case 4:
		{
			brand = "Mercedes";
		}
		break;
		case 5:
		{
			brand = "Nissan";
		}
		break;
		case 6:
		{
			brand = " Renault";
		}
		break;
		case 7:
		{
			brand = "BMW";
		}
		break;
		case 8:
		{
			brand = "Volvo";
		}
		break;
		case 9:
		{
			brand = "Peugeot";
		}
		break;
		default:
		{
			brand = "Lada";

		}
		}
		speed = 20 + (rand() % static_cast<int>(40 - 20 + 1));//min + (rand() % static_cast<int>(max - min + 1))
		capacity = 40 + (rand() % static_cast<int>(60 - 40 + 1));
		payment = 5 + (rand() % static_cast<int>(10 - 5 + 1));
	}
	taxi(string Brand, string Tvehicle, int Speed, int Capacity, int Payment) : car(Brand, Tvehicle, Speed, Capacity), payment(Payment) {}
	void SetPayment() { cin >> payment; }

	int GetPayment() { return payment; }

	void SetInfo()
	{
		car::SetInfo();
		cout << setw(25) << "Enter your payment: "; cin >> payment;
	}

	void ShowInfo() {
		car::ShowInfo();
		cout << setw(35) << "Average payment(in rubles): " << payment << endl;
	}
	friend ostream &operator <<(ostream&s, taxi&d)
	{
		s << setw(35) << "Info about transport" << endl;
		s << setw(35) << "Type of vehicle: " << d.tvehicle << endl;
		s << setw(35) << "Type of brand: " << d.brand << endl;
		s << setw(35) << "Average speed: " << d.speed << endl;
		s << setw(35) << "Average capacity: " << d.capacity << endl;
		s << setw(35) << "Average payment(in rubles): " << d.payment << endl;
		return s;
	}

	void writefile(ofstream &ofs, ofstream &out, bicycle *A)
	{
		int a = 2;
		out << a << endl;
		ofs.write(reinterpret_cast<char*>(A), sizeof(taxi));
	}
	taxi* readfile(ifstream &ifs)
	{
		ifs.read(reinterpret_cast<char*>(this), sizeof(taxi));
		return new taxi(*this);
	}
};

class minibus : public taxi {
protected:
	int passengers;

public:
	minibus()
	{
		tvehicle = "Minibus";
		int i = (rand() % 1) + 1;
		switch (i)
		{

		case 1:
		{
			brand = "Volkswagen";
		}
		break;

		case 2:
		{
			brand = "MAZ";
		}
		break;
		default:
		{
			brand = "Lada";

		}
		}
		speed = 20 + (rand() % static_cast<int>(40 - 20 + 1));//min + (rand() % static_cast<int>(max - min + 1))
		capacity = 40 + (rand() % static_cast<int>(60 - 40 + 1));
		payment = 1 + (rand() % static_cast<int>(2 - 1 + 1));
		passengers = 15 + (rand() % static_cast<int>(20 - 15 + 1));
	}
	minibus(string Brand, string Tvehicle, int Speed, int Capacity, int Payment, int Passengers) :taxi(Brand, Tvehicle, Speed, Capacity, Payment), passengers(Passengers) {}
	void SetPassengers() { cin >> passengers; }

	int GetPassengers() { return passengers; }

	void SetInfo()
	{
		taxi::SetInfo();
		cout << setw(25) << "Enter amount of passengers: "; cin >> passengers;
	}

	void ShowInfo() {
		taxi::ShowInfo();
		cout << setw(35) << "Average amount of passengers: " << passengers << endl;
	}
	friend ostream &operator <<(ostream&s, minibus&d)
	{
		s << setw(35) << "Info about transport" << endl;
		s << setw(35) << "Type of vehicle: " << d.tvehicle << endl;
		s << setw(35) << "Type of brand: " << d.brand << endl;
		s << setw(35) << "Average speed: " << d.speed << endl;
		s << setw(35) << "Average capacity: " << d.capacity << endl;
		s << setw(35) << "Average payment(in rubles): " << d.payment << endl;
		s << setw(35) << "Average amount of passengers: " << d.passengers << endl;
		return s;
	}

	void writefile(ofstream &ofs, ofstream &out, bicycle *A)
	{
		int a = 3;
		out << a << endl;
		ofs.write(reinterpret_cast<char*>(A), sizeof(minibus));
	}
	minibus* readfile(ifstream &ifs)
	{
		ifs.read(reinterpret_cast<char*>(this), sizeof(minibus));
		return new minibus(*this);
	}
};

class bus : public minibus {
protected:
	int stops;

public:
	bus()
	{
		tvehicle = "Bus";
		brand = "MAZ";
		speed = 20 + (rand() % static_cast<int>(40 - 20 + 1));//min + (rand() % static_cast<int>(max - min + 1))
		capacity = 40 + (rand() % static_cast<int>(60 - 40 + 1));
		payment = 1;
		passengers = 90 + (rand() % static_cast<int>(110 - 90 + 1));
		stops = 15 + (rand() % static_cast<int>(30 - 15 + 1));
	}
	bus(string Brand, string Tvehicle, int Speed, int Capacity, int Payment, int Passengers, int Stops) :minibus(Brand, Tvehicle, Speed, Capacity, Payment, Passengers), stops(Stops) {}

	void SetStops() { cin >> stops; }
	int GetStops() { return stops; }

	void SetInfo()
	{
		minibus::SetInfo();
		cout << setw(25) << "Enter amount of stops: "; cin >> stops;
	}

	void ShowInfo() {
		minibus::ShowInfo();
		cout << setw(35) << "Average amount of stops: " << stops << endl;
	}
	friend ostream &operator <<(ostream&s, bus&d)
	{
		s << setw(35) << "Info about transport" << endl;
		s << setw(35) << "Type of vehicle: " << d.tvehicle << endl;
		s << setw(35) << "Type of brand: " << d.brand << endl;
		s << setw(35) << "Average speed: " << d.speed << endl;
		s << setw(35) << "Average capacity: " << d.capacity << endl;
		s << setw(35) << "Average payment(in rubles): " << d.payment << endl;
		s << setw(35) << "Average amount of passengers: " << d.passengers << endl;
		s << setw(35) << "Average amount of stops: " << d.stops << endl;
		return s;
	}

	void writefile(ofstream &ofs, ofstream &out, bicycle *A)
	{
		int a = 4;
		out << a << endl;
		ofs.write(reinterpret_cast<char*>(A), sizeof(bus));
	}
	bus* readfile(ifstream &ifs)
	{
		ifs.read(reinterpret_cast<char*>(this), sizeof(bus));
		return new bus(*this);
	}

};

class underground :public bus {
protected:
	int interval;
public:
	underground() {
		tvehicle = "Underground";
		brand = "None";
		speed = 30 + (rand() % static_cast<int>(50 - 30 + 1));//min + (rand() % static_cast<int>(max - min + 1))
		capacity = 0;
		payment = 1;
		passengers = 361;
		stops = 14 + (rand() % static_cast<int>(15 - 14 + 1));
		interval = 2 + (rand() % static_cast<int>(5 - 2 + 1));

	}
	underground(string Brand, string Tvehicle, int Speed, int Capacity, int Payment, int Passengers, int Stops, int Interval) :bus(Brand, Tvehicle, Speed, Capacity, Payment, Passengers, Stops), interval(Interval) {}

	void SetInterval() { cin >> interval; }
	int GetInterval() { return interval; }

	void SetInfo()
	{
		bus::SetInfo();
		cout << setw(25) << "Enter interval of time: "; cin >> interval;
	}

	void ShowInfo() {
		bus::ShowInfo();
		cout << setw(35) << "Average interval of time: " << interval << endl;
	}
	friend ostream &operator <<(ostream&s, underground&d)
	{
		s << setw(35) << "Info about transport" << endl;
		s << setw(35) << "Type of vehicle: " << d.tvehicle << endl;
		s << setw(35) << "Type of brand: " << d.brand << endl;
		s << setw(35) << "Average speed: " << d.speed << endl;
		s << setw(35) << "Average capacity: " << d.capacity << endl;
		s << setw(35) << "Average payment(in rubles): " << d.payment << endl;
		s << setw(35) << "Average amount of passengers: " << d.passengers << endl;
		s << setw(35) << "Average amount of stops: " << d.stops << endl;
		s << setw(35) << "Average interval of time: " << d.interval << endl;

		return s;
	}

	void writefile(ofstream &ofs, ofstream &out, bicycle *A)
	{
		int a = 5;
		out << a << endl;
		ofs.write(reinterpret_cast<char*>(A), sizeof(underground));
	}
	underground* readfile(ifstream &ifs)
	{
		ifs.read(reinterpret_cast<char*>(this), sizeof(underground));
		return new underground(*this);
	}
};

class massiv:public bicycle, public car, public taxi, public minibus, public bus,public underground
{
protected:
	//int size;
	//bicycle **a =  bicycle[size];//{ NULL };
	vector<bicycle*>a;
	int size;
public:

	massiv()
	{
		size = (rand() % 10) + 1;
		for (int i = 0; i < size; i++)a.push_back(new car);
	}

	massiv(int k)
	{
		size = k;
		for (int i = 0; i < size; i++)a.push_back(new car);
	}

	massiv(const massiv &m)
	{
		for (int i = 0; i < sizeof(a); i++) {
			a.pop_back();
		}
		size = m.size;
		for (int i = 0; i < size; i++) {
			a.push_back(m.a[i]);
		}

	}

	massiv(massiv& m) {//конст перемещения
		for (int i = 0; i < sizeof(a); i++) {
			a.pop_back();
		}
		size = m.size;
		for (int i = 0; i < size; i++) {
			a.push_back(m.a[i]);
		}
		m.DeleteAll();

	}


	void create(int n)
	{
		this->size = n; 
		a.clear();
		for (int i = 0; i < size; i++)
		{
			//bicycle A;
			a.push_back( new car);
		}
	}

	~massiv()
	{
		ofstream outfile;
		for (int i = 0; i < size; i++)
			outfile << a[0];

		a.clear(); size = 0;
	}
	
	bicycle* &operator[](const int i)
	{
		assert(i >= 0 && i < size);
		return a[i];
	}

	massiv& operator=(const massiv& m)
	{
		DeleteAll(); 
		size = m.size;
		for (int i = 0; i < size; i++) {
			a.push_back(m.a[i]);
		}
		return *this;
	}

	void Add()
	{
		int vibor; cout << "Choose which class do u want to add?(1-car,2-taxi,3-bus,4-minibus,5-underground)"; cin >> vibor;
		switch (vibor)
		{
		case 1: {a.push_back(new car); size++; }break;
		case 2: {a.push_back(new taxi); size++; } break;
		case 3: {a.push_back(new bus); size++; } break;
		case 4: {a.push_back(new minibus); size++; } break;
		case 5: {a.push_back(new underground); size++; } break;
		default: a.push_back(new car); size++;
		}

	}

	void Print()
	{
		for (int i = 0; i < size; i++) a[i]->ShowInfo();
	}

	void Delete(int k)
	{
		a.erase(a.begin() + k); size--;
	}

	void DeleteAll()
	{
		a.clear(); size = 0;
	}

	massiv CreateMassiv()
	{
		massiv retBuff;
		return retBuff;
	}

	void Move(massiv& m) {//op перемещения
		for (int i = 0; i < sizeof(a); i++) {
			a.pop_back();
		}
		size = m.size;
		for (int i = 0; i < size; i++) {
			a.push_back(m.a[i]);
		}
		m.DeleteAll();

	}
	void operator&( massiv &A)
	{
		this->size = A.size;
		a.clear();
		//array = new Math*[size];
		for (int i = 0; i < size; i++)
		{
			a.push_back(A[i]);
		}
	}
	void operator=(massiv&& A)
	{
		a.clear(); size = A.size;
		for (int i = 0; i < size; i++)
		{
			a.push_back(A[i]);
		}
		
		
	}
	
	void writefile(ofstream &ofs, ofstream &out, string path)
	{
		for (int i = 0; i < size; i++)
		{
			a[i]->writefile(ofs, out, a[i]);
		}
	}
	void readfile(ifstream &ifs, ifstream &in)
	{

		for (int i = 0; i < size; i++)
		{
			int b;
			in >> b;
			if (b == 0)
			{
				a[i] = bicycle::readfile(ifs);
			}
			if (b == 1)
			{
				a[i] = car::readfile(ifs);
			}
			if (b == 2)
			{
				a[i] = taxi::readfile(ifs);
			}
			if (b == 3)
			{
				a[i] = minibus::readfile(ifs);
			}
			if (b == 4)
			{
				a[i] = bus::readfile(ifs);
			}


		}
	}

	friend ostream &operator <<(ostream&s, massiv&d)
	{
		for (int i = 0; i < d.size; i++) {
			s << d.a[i] << endl;
		}

		return s;
	}
};






