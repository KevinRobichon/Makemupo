#pragma once

namespace MKPatterns
{

	template<typename T> class Singleton
	{
	public:
		static T* getInstance()
		{
			if (m_instance == NULL)
				m_instance = new T();
		}

		static void destroy()
		{
			if (m_instance != NULL)
				delete m_instance;
			m_instance = NULL;
		}
	protected:
		static T*  m_instance;
	private:
		Singleton(){};
		~Singleton(){};
	};

};