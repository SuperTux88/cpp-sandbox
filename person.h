#ifndef __PERSON_H__
#define __PERSON_H__
#include <string>
	class Person {
		public:
			Person();
			Person(std::string name);
			virtual ~Person();
			std::string name;
			virtual void hello();
	};
#endif
