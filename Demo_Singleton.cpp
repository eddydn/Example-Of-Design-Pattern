
/*
	Name: Demo_Singleton.cpp
	Copyright: 2018
	Author: nguyenthoanglinh@dtu.edu.vn  aka eddydn@gmail.com
	Date: 07/11/18 13:58
	Description: Cai dat design pattern Singleton
*/


#include <iostream>
using namespace std;


class MediaPlayer
{
	private:
		static MediaPlayer * m_instance;
		MediaPlayer();
	public:
		static MediaPlayer* getInstance();
		void play();
		void pause();
		void stop();
};


// Init Instance
MediaPlayer* MediaPlayer::m_instance = NULL;

MediaPlayer::MediaPlayer(){
}

MediaPlayer* MediaPlayer::getInstance()
{
	if(m_instance == NULL)
		m_instance = new MediaPlayer(); 
	return m_instance; 
}

void MediaPlayer::play()
{
	cout << "Media Player Play"<<endl;
}

void MediaPlayer::pause()
{
	cout << "Media Player Pause"<<endl;
}

void MediaPlayer::stop()
{
	cout << "Media Player Stop"<<endl;
}


int main()
{
	MediaPlayer* mediaPlayer = MediaPlayer::getInstance();
	mediaPlayer->play();
	mediaPlayer->pause();
	mediaPlayer->stop();
	return 0;
}
