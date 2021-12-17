#include<iostream>
using namespace std;
class Weapon {
protected:
	string m_name;
	int m_damage;
	double m_distance;
public:
	Weapon(string name="", int damage=0, double distance=0.0):
		m_name{name},m_damage{damage},m_distance{distance}
	{}
	void setName(string name) { m_name = name; }
	void setDamage(int damage) { m_damage = damage; }
	void setDistance(double distance) { m_distance = distance; }
	string getName() { return m_name; }
	int getDamage() { return m_damage; }
	double getDistance(){ return m_distance; }
	void print() {
		cout << "Name: " << m_name << ' '<<"Damage: " << m_damage << ' ' << "Distance: " << m_distance << endl;
	}
};
class Granate :public Weapon {
private:
	double m_radius;
public:
	Granate(string name = "", int damage = 0, double distance = 0.0,double radius=0.0):
		Weapon(name,damage,distance),m_radius{radius}
	{}
	void setRadius(int radius) { m_radius = radius; }
	double getRadius() { return m_radius; }
	void print() {
		Weapon::print();
		cout << "Radius: " << m_radius << endl;
	}
	void blowup() {
		cout << "Granade has blew up!" << endl;
	}
};
class Pistol :public Weapon {
private:
	const int ammo_in_oboyma=15;
	int m_ammo_count;
public:
	Pistol(string name = "", int damage = 0, double distance = 0.0, int ammo_count=0) :
		Weapon(name, damage, distance), m_ammo_count{ ammo_count }
	{}
	void setAmmoCount(int ammo_count) { m_ammo_count = ammo_count; }
	double getAmmoCount() { return m_ammo_count; }
	bool have() { return m_ammo_count > 0; }
	void fire() {
		if (have()) {
			cout << "Fire!\n";
			m_ammo_count--;
		}
		else {
			cout << "No ammo\n";
		}
	}
	void reload() {
		m_ammo_count = ammo_in_oboyma;
	}
	void print() {
		Weapon::print();
		cout << "Ammo: " << m_ammo_count << endl;
	}
};
int main() {
	Granate g1("F1", 100, 20, 200);
	g1.print();
	g1.blowup();
	Pistol p1("Glock", 10, 50, 5);
	while (p1.have()) {
		p1.fire();
	}
	p1.fire();
	p1.reload();
	p1.print();
}