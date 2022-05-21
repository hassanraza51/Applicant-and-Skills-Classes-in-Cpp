#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

class Skill{
    private:
        string name;
    
    public:
        // constructor
        Skill(string name){
            this->name = name;
        }
        // getter of name
        string getName() const {
            return name;
        } 
};
class Applicant{
    private:
        string name;
        vector<Skill> skills;
    
    public:
        // default constructor
        Applicant(){
            name = "";
        }
        // constructor
        Applicant(string name){
            this->name = name;
        }
        // add skills to Applicant
        void addSkill(string skillName){
            skills.push_back(skillName);
        }
        // getter of name
        string getName() const {
            return name;
        }
        vector<Skill> getSkills(){
            return skills;
        }
};

int main()
{
    // declare File instance
    ifstream inFile;
    // open the ApplicantsFile.txt File
    inFile.open("ApplicantsFile.txt");
    // if file cannot open
    if(!inFile){
        cout << "File cannot be open" << endl;
        return -1;
    }
    int numApplicants = 0;
    // iterate till end of the file
    while(!inFile.eof()){
        string temp;
        getline(inFile, temp);
        numApplicants++;
    }
    inFile.close();
    
    // reopen the ApplicantsFile.txt File
    inFile.open("ApplicantsFile.txt");
    // create an array of Applicant
    Applicant applicants[numApplicants];
    int index = 0;
    // iterate till end of the file
    while(!inFile.eof()){
        string applicantName;
        // read the applicantName
        inFile >> applicantName;
        Applicant applicant(applicantName);
        // read the skills
        string skills;
        getline(inFile, skills);
        stringstream ss(skills);
        string skill;
        // iterate and add skill to the applicant
        if(getline(ss,skill)){
            applicant.addSkill(skill);
        }
        vector<Skill> appSkills = applicant.getSkills();
        cout << applicant.getName();
        // iterate through the skills and display the skills
        for(int index = 0; index < appSkills.size(); index++){
            cout << appSkills.at(index).getName() << endl;
        }
    }
    inFile.close();
    
    return 0;
}