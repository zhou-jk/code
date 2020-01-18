#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int N_Minerals;

class Troop{
public:
	Troop(){}
    Troop(string New_Troop_Name, int New_Wasting_Minerals)
    :Troop_Name(New_Troop_Name), Wasting_Minerals(New_Wasting_Minerals), N_This_Troops(1){
    	cout << '#' << endl; 
    }
    Troop(const Troop& New_Troop) //使用Troop(string, int)生成的是临时变量,属于右值,需要使用const传参 
	:Troop_Name(New_Troop.Troop_Name), Wasting_Minerals(New_Troop.Wasting_Minerals), N_This_Troops(New_Troop.N_This_Troops) 
	{
		/*Troop_Name = New_Troop.Troop_Name;
		Wasting_Minerals = New_Troop.Wasting_Minerals;
		N_This_Troops = New_Troop.N_This_Troops;*/ 
		//cout << "c" << Troop_Name << endl;
	}
	Troop(Troop& New_Troop)
	:Troop_Name(New_Troop.Troop_Name), Wasting_Minerals(New_Troop.Wasting_Minerals), N_This_Troops(New_Troop.N_This_Troops) 
	{
		/*Troop_Name = New_Troop.Troop_Name;
		Wasting_Minerals = New_Troop.Wasting_Minerals;
		N_This_Troops = New_Troop.N_This_Troops;*/
		//cout << "n" << Troop_Name << endl;
	}
	/*~Troop() {}*/ 
    int Get_Wasting_Minerals() {
        return Wasting_Minerals;
    }
    int Greate_a_New_Unit(int N_Troops){
        cout << Troop_Name << ' ' << N_Troops << " born with HP " << 
        Wasting_Minerals << ' ' << N_This_Troops << ' '<< Troop_Name << ' ';
        N_This_Troops++;
        return Wasting_Minerals;
    }
private:
    string Troop_Name;
    int Wasting_Minerals, N_This_Troops;
};

class Base{
public:
    Base(string New_Base_Name, int New_N_Minerals, Troop New_Troops[3])
	:Base_Name(New_Base_Name), N_Minerals(New_N_Minerals), N_Troops(0)  {
		for (int i = 0; i < 3; i++) Troops[i] = New_Troops[i]; //对象数组不能直接使用初始化列表 
	}
    ~Base() {
        cout << Base_Name << " base stop training troopers." << endl;
    }
    int Get_N_Minerals() {
    	return N_Minerals;
	}
    void Greate_a_New_Unit(int &i) {
        cout << Base_Name << ' ';
        while (Troops[i].Get_Wasting_Minerals() > N_Minerals) {
		    i++;
		    i %= 3;
		} 
        N_Minerals -= Troops[i].Greate_a_New_Unit(N_Troops);
        cout << "in base " << Base_Name << endl;
        N_Troops++;
    }
private:
    Troop Troops[3];
    string Base_Name; 
    int N_Minerals, N_Troops;
};

void New_Party(string name, Troop Troops[3]) {
        Base New_Base(name, N_Minerals, Troops);
        int t, i;
        for (i = t = 0; New_Base.Get_N_Minerals() >= 4; t++) {	
            cout << "Time: " << t << "  ";
            i %= 3;
            New_Base.Greate_a_New_Unit(i);
            i++;
        }
        cout << "Time: " << t - 1 << "  ";
}

int main() {
    cin >> N_Minerals;
    /*Troop Troop1("1", 1);
	Troop Troop2(Troop1);
	Troop Troop3 = Troop("2", 2);*/ 
    Troop Troops1[3]={Troop("SCV", 10), Troop("Marine", 5), Troop("Medic", 4)}; 
    //cout << Troops1[0].Get_Wasting_Minerals(); 
    New_Party("Raynor", Troops1);
    Troop Troops2[3]={Troop("Marine", 5), Troop("Medic", 4), Troop("SCV", 10)};
    New_Party("Mengsk",Troops2);
    return 0;
}
