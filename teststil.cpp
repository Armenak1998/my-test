#include<iostream>
#include<fstream>
#include<string>
//#include<map>
void Is_Corect_Stil_For_If(std::string line, int namberline) {
    if (std::string::npos == line.find(" if")) {
        return;
    }

    if ((std::string::npos == line.find(" if (")) && (std::string::npos != line.find(" if("))) {
            std::cout<<"####################################################################\n";
            std::cout<<"in line:"<<namberline<<'\n';
            std::cout<<line<<'\n';
            std::cout<<"<if> is incorrect <if()> but should be <if ()>\n";
            std::cout<<"####################################################################"<<std::endl;
    }

    if (std::string::npos == line.find(") {")) {
            std::cout<<"####################################################################\n";
            std::cout<<"in line:"<<namberline<<'\n';
            std::cout<<line<<'\n';
            std::cout<<"<if> don't have <{}>\n";
            std::cout<<"####################################################################"<<std::endl;
    }

}

void Is_Corect_Stil_For_Else(std::string line, int namberline) {
    if (std::string::npos == line.find(" else")) {
        return;
    }

    if (std::string::npos == line.find("} else {")) {
            std::cout<<"####################################################################\n";
            std::cout<<"in line:"<<namberline<<'\n';
            std::cout<<line<<'\n';
            std::cout<<"<else> is incorrect sitax this is corect stile <} else {>\n";
            std::cout<<"####################################################################"<<std::endl;
    }
}

void Is_Corect_Stil_For_Comma(std::string line, int namberline) {
    if (std::string::npos == line.find(",")) {
        return;
    }

    const int& index = line.find(",") + 1;
    if ((line.size()==index) || (line[index] != ' ')) {
            std::cout<<"####################################################################\n";
            std::cout<<"in line:"<<namberline<<'\n';
            std::cout<<line<<'\n';
            std::cout<<"<,> is incorrect sitax this is corect stile <, >\n";
            std::cout<<"####################################################################"<<std::endl;
    }
}

void Is_Corect_Stil_For_For(std::string line, int namberline) {
    if (std::string::npos == line.find("for")) {
        return;
    }

    if ((std::string::npos == line.find(" for (")) && (std::string::npos != line.find(" for("))) {
            std::cout<<"####################################################################\n";
            std::cout<<"in line:"<<namberline<<'\n';
            std::cout<<line<<'\n';
            std::cout<<"<for> is incorrect <for()> but should be <for ()>\n";
            std::cout<<"####################################################################"<<std::endl;
    }

    if (std::string::npos == line.find(") {")) {
            std::cout<<"####################################################################\n";
            std::cout<<"in line:"<<namberline<<'\n';
            std::cout<<line<<'\n';
            std::cout<<"<for> don't have <{}>\n";
            std::cout<<"####################################################################"<<std::endl;
    }

    if (std::string::npos == line.find(";")) {
        return;
    }

    const int& index = line.find(";") + 1;
    if ((line.size()==index) || (line[index] != ' ')) {
            std::cout<<"####################################################################\n";
            std::cout<<"in line:"<<namberline<<'\n';
            std::cout<<line<<'\n';
            std::cout<<"in <for> <;> is incorrect sitax this is corect stile <; >\n";
            std::cout<<"####################################################################"<<std::endl;
    }
}

bool is_valid_simvol(std::string line, int index) {
     switch (line[index]) {
         case '!' : return true;
         case '>' : return true;
         case '<' : return true;
         case '=' : return true;
         default : return false;
         }
     return false;
}

void Is_Corect_Stil_For_IF_ERROR(std::string line, int namberline) {
    if (std::string::npos == line.find("if")) {
        return;
    }

    const auto& index = line.rfind("=");
    if (index == std::string::npos) {
        return ;
    }

    if (((index - 1) < 0) || !is_valid_simvol(line, (index - 1))) {
        std::cout<<"####################################################################\n";
        std::cout<<"############################ERROR###################################\n";
        std::cout<<"####################################################################\n";
        std::cout<<"in line:"<<namberline<<'\n';
        std::cout<<line<<'\n';
        std::cout<<"is ERROR sitax this is corect stile \n";
        std::cout<<"####################################################################"<<std::endl;
    }
}
/*
std::string get_Action_1(int index) {
    static std::map<int,std::string>
        action_map = {
            {1, "+"},
            {2, "-"},
            {3, "*"},
            {4, "/"},
            {5, "|"},
            {6, "&"},
            {7, "%"},
            {8, "^"},
            {9, "="},
    };
    return action_map[index];
}
std::string get_Action_2(int index) {
    static std::map<int,std::string>
        action_map = {
            {0, "==" },
            {1, "<<" },
            {2, ">>" },
            {2, "+=" },
            {4, "-=" },
            {5, "*=" },
            {6, "/=" },
            {7, "|=" },
            {8, "&=" },
            {9, "%=" },
            {10, "^="},
            {11, "<" },
            {12, ">" },
            {13, ">="},
            {14, "<="},
            {15, "!="}
    };
    return action_map[index];
}
void Is_Corect_Stil_For_Action(std::string line, int namberline) {
    for (int i = 0; i < 10; ++i) {
        const auto& index = line.find(get_Action_1(i));

        if (index == std::string::npos) {
            continue;
        }

        if ((index == 0) || (index == (line.size() - 1)) || (line[index - 1] != ' ') || (line[index + 1] != ' ')) {
            std::cout<<"####################################################################\n";
            std::cout<<"in line:"<<namberline<<'\n';
            std::cout<<line<<'\n';
            std::cout<<"is incorect action sitax  \n";
            std::cout<<"####################################################################"<<std::endl;
        }
    }
    for (int i = 0; i < 16; ++i) {
        const auto& index = line.find(get_Action_2(i));

        if (index == std::string::npos) {
            continue;
        }

        if ((index == 0) || (index > (line.size() - 3)) || (line[index - 1] != ' ') || (line[index + 2] != ' ')) {
            std::cout<<"####################################################################\n";
            std::cout<<"in line:"<<namberline<<'\n';
            std::cout<<line<<'\n';
            std::cout<<"is incorect action sitax  \n";
            std::cout<<"####################################################################"<<std::endl;
        }
    }
}
*/
int main()
{
    std::string filename;
    std::cout<<"file name which wont testing >>"<<std::flush;
    std::cin>> filename;
    std::ifstream ifile;
    ifile.open(filename); // bacumem file.txt
    if (!ifile.is_open()) {
        std::cout<<"ERROR: is not open"<<std::endl;
    }
    std::string line;
    int i = 1;
    while (!ifile.eof()) {
        std::getline(ifile,line);
        Is_Corect_Stil_For_If(line,i);
        Is_Corect_Stil_For_Else(line,i);
        Is_Corect_Stil_For_Comma(line,i);
        Is_Corect_Stil_For_For(line,i);
        Is_Corect_Stil_For_IF_ERROR(line,i);
        //Is_Corect_Stil_For_Action(line,i);
        ++i;
    }
    ifile.close();
    return 0;
}
