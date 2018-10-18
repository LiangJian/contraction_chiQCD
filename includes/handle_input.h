#ifndef __HANDLE_INPUT__
#define __HANDLE_INPUT__

#include <boost/program_options.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

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
      try{
      //po::store(po::parse_config_file(settings_file,*desc,true), pw);  // true is to allow unknown parameters
      po::store(po::parse_config_file(settings_file,*desc), pw);
      po::notify(pw);
      }
      catch (po::error& e) {
      std::cerr << "Error: " << e.what() << "\n";
      exit(1);
      }
    };

    void add(std::string name, double ini_value, std::string intro=""){
      desc->add_options()(name.c_str(), po::value<double>()->default_value(ini_value),  intro.c_str());
      pw_type.insert(std::pair <std::string, Types> (name, double_));
    };

    void add(std::string name, int ini_value, std::string intro=""){
      desc->add_options()(name.c_str(), po::value<int>()->default_value(ini_value), intro.c_str());
      pw_type.insert(std::pair <std::string, Types> (name, int_));
    };

    void add(std::string name, std::string ini_value, std::string intro=""){
      desc->add_options()(name.c_str(), po::value<std::string>()->default_value(ini_value), intro.c_str());
      pw_type.insert(std::pair <std::string, Types> (name, string_));
    };

    void list(){
	std::cout<<"**********************************************************"<<std::endl;
	int count = 1;
	for (std::map<std::string, Types>::iterator it=pw_type.begin(); it!=pw_type.end(); ++it, count++){
	    try{
            if(pw[it->first].defaulted()) std::cout << std::setw(20) << it->first<< " not found in the input file, using the defualt value..."<<std::endl;
	    if(it->second == int_){
	      std::cout<< std::setw(2) << count << std::setw(20)<< it->first << "\t <= \t" << pw[it->first].as<int>() << '\n';
	    }
	    if(it->second == double_){
	      std::cout<< std::setw(2) << count << std::setw(20)<< it->first << "\t <= \t" << pw[it->first].as<double>() << '\n';
	    }}
	    catch (po::error& e) {
	    std::cerr << "Error: " << e.what() << "\n";
	    exit(1);
	    }
	    catch (boost::bad_any_cast) {
	    std::cerr << "Error: " << "parameters not properly read\n";
	    exit(1);
	    }
	}
	std::cout<<"**********************************************************"<<std::endl;
    };
};

#endif
