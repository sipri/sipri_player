#include "stdafx.h"
#include "Main.h"

using namespace sipri_mp3_player;

MainForm::MainForm(void)
{
	InitializeComponent();

	m_PlayControl = gcnew CPlayControl();
	m_PlayStaus = EPlayStatus::STOP;
}

MainForm::~MainForm(void)
{
	if(components){
		delete components;
	}

	if(m_PlayControl){
		delete m_PlayControl;
	}
}

System::Void MainForm::m_buttonPlay_Click(System::Object^  sender, System::EventArgs^  e)
{
	if(nullptr == m_listPlay->SelectedItem){
		return;
	}

	String^ pFileName = m_listPlay->SelectedItem->ToString();

	if(EPlayStatus::STOP == m_PlayStaus){
		m_PlayControl->SetFile(pFileName);
		m_PlayControl->Play();
		m_PlayStaus = EPlayStatus::PLAY;
	}else if(EPlayStatus::PAUSE == m_PlayStaus){
		m_PlayControl->Resume();
		m_PlayStaus = EPlayStatus::PLAY;
	}
}

System::Void MainForm::m_buttonPause_Click(System::Object^  sender, System::EventArgs^  e)
{
	m_PlayControl->Pause();
	m_PlayStaus = EPlayStatus::PAUSE;
}

System::Void MainForm::m_buttonStop_Click(System::Object^  sender, System::EventArgs^  e)
{
	m_PlayControl->Stop();
	m_PlayStaus = EPlayStatus::STOP;
}

System::Void MainForm::m_buttonPrev_Click(System::Object^  sender, System::EventArgs^  e)
{
	if(m_listPlay->SelectedIndex <= 0){
		return;
	}
	
	m_listPlay->SelectedIndex--;

	String^ pFileName = m_listPlay->SelectedItem->ToString();
	m_PlayControl->SetFile(pFileName);
	m_PlayControl->Play();
	m_PlayStaus = EPlayStatus::PLAY;
}

System::Void MainForm::m_buttonNext_Click(System::Object^  sender, System::EventArgs^  e)
{
	if((m_listPlay->Items->Count-1) <= m_listPlay->SelectedIndex){
		return;
	}

	m_listPlay->SelectedIndex++;

	String^ pFileName = m_listPlay->SelectedItem->ToString();
	m_PlayControl->SetFile(pFileName);
	m_PlayControl->Play();
	m_PlayStaus = EPlayStatus::PLAY;
}

System::Void MainForm::m_listPlay_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e)
{
	array<String^>^ pFileList = (array<String^>^)e->Data->GetData(DataFormats::FileDrop, false);
	for(int iCnt=0; iCnt<pFileList->Length; iCnt++){
		m_listPlay->Items->Add(pFileList[iCnt]);
	}
}

System::Void MainForm::m_listPlay_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e)
{
	if(e->Data->GetDataPresent(DataFormats::FileDrop)){
		e->Effect = DragDropEffects::All;
	}else{
		e->Effect = DragDropEffects::None;
	}
}

System::Void MainForm::m_listPlay_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	m_PlayStaus = EPlayStatus::STOP;
}
