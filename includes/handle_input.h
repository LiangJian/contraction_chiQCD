#include <boost/program_options.hpp>
#include <iostream>
#include <fstream>
#include <string>

namespace po = boost::program_options;
class handle_inputs{

  public:
    po::options_description *desc;
    po::variables_map pw;
    std::string filename;
    enum Types{
	int_,
	double_,
	string_,
	int_vector_,
	double_vector_,
	string_vector
    };
    std::map <std::string, Types> pw_type;


    handle_inputs(std::string filename_){

	filename = filename_;

	desc = new po::options_description("Options");
    }

    void read(){
      std::ifstream settings_file(filename);
      po::store(po::parse_config_file(settings_file,*desc), pw);
      po::notify(pw);    
    };

    void add(std::string name, double ini_value){
      desc->add_options()(name.c_str(), po::value<double>(),  (std::string("set ")+name).c_str());
      pw_type.insert(std::pair <std::string, Types> (name, double_));
    };

    void add(std::string name, int ini_value){
      desc->add_options()(name.c_str(), po::value<int>(),  (std::string("set ")+name).c_str());
      pw_type.insert(std::pair <std::string, Types> (name, int_));
    };

    void list(){
	for (std::map<std::string, Types>::iterator it=pw_type.begin(); it!=pw_type.end(); ++it)
	  std::cout << it->first << " <= " << pw["nx"].as<int>() << '\n';
    };
};

void ini_input();
