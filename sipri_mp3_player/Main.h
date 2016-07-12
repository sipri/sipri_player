#pragma once

#include "PlayControl.h"
#include "PlayStatus.h"

namespace sipri_mp3_player {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void);
		~MainForm(void);

	private: System::Windows::Forms::TableLayoutPanel^  m_tableButtons;
	private: System::Windows::Forms::Button^  m_buttonPlay;
	private: System::Windows::Forms::Button^  m_buttonPause;
	private: System::Windows::Forms::Button^  m_buttonStop;
	private: System::Windows::Forms::Button^  m_buttonPrev;
	private: System::Windows::Forms::Button^  m_buttonNext;
	private: System::Windows::Forms::TableLayoutPanel^  m_tablePlayer;
	private: System::Windows::Forms::ListBox^  m_listPlay;
	private: System::ComponentModel::Container ^components;

	private: sipri_mp3_player::CPlayControl^ m_PlayControl;
	private: EPlayStatus m_PlayStaus;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->m_tableButtons = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->m_buttonPlay = (gcnew System::Windows::Forms::Button());
			this->m_buttonPause = (gcnew System::Windows::Forms::Button());
			this->m_buttonStop = (gcnew System::Windows::Forms::Button());
			this->m_buttonPrev = (gcnew System::Windows::Forms::Button());
			this->m_buttonNext = (gcnew System::Windows::Forms::Button());
			this->m_tablePlayer = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->m_listPlay = (gcnew System::Windows::Forms::ListBox());
			this->m_tableButtons->SuspendLayout();
			this->m_tablePlayer->SuspendLayout();
			this->SuspendLayout();
			// 
			// m_tableButtons
			// 
			this->m_tableButtons->AutoSize = true;
			this->m_tableButtons->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->m_tableButtons->ColumnCount = 5;
			this->m_tableButtons->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				20)));
			this->m_tableButtons->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				20)));
			this->m_tableButtons->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				20)));
			this->m_tableButtons->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				20)));
			this->m_tableButtons->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				20)));
			this->m_tableButtons->Controls->Add(this->m_buttonPlay, 0, 0);
			this->m_tableButtons->Controls->Add(this->m_buttonPause, 1, 0);
			this->m_tableButtons->Controls->Add(this->m_buttonStop, 2, 0);
			this->m_tableButtons->Controls->Add(this->m_buttonPrev, 3, 0);
			this->m_tableButtons->Controls->Add(this->m_buttonNext, 4, 0);
			this->m_tableButtons->Dock = System::Windows::Forms::DockStyle::Fill;
			this->m_tableButtons->Location = System::Drawing::Point(3, 433);
			this->m_tableButtons->Name = L"m_tableButtons";
			this->m_tableButtons->RowCount = 1;
			this->m_tableButtons->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->m_tableButtons->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->m_tableButtons->Size = System::Drawing::Size(286, 33);
			this->m_tableButtons->TabIndex = 2;
			// 
			// m_buttonPlay
			// 
			this->m_buttonPlay->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->m_buttonPlay->Location = System::Drawing::Point(3, 5);
			this->m_buttonPlay->Name = L"m_buttonPlay";
			this->m_buttonPlay->Size = System::Drawing::Size(51, 23);
			this->m_buttonPlay->TabIndex = 0;
			this->m_buttonPlay->Text = L"|>";
			this->m_buttonPlay->UseVisualStyleBackColor = true;
			this->m_buttonPlay->Click += gcnew System::EventHandler(this, &MainForm::m_buttonPlay_Click);
			// 
			// m_buttonPause
			// 
			this->m_buttonPause->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->m_buttonPause->Location = System::Drawing::Point(60, 5);
			this->m_buttonPause->Name = L"m_buttonPause";
			this->m_buttonPause->Size = System::Drawing::Size(51, 23);
			this->m_buttonPause->TabIndex = 1;
			this->m_buttonPause->Text = L"||";
			this->m_buttonPause->UseVisualStyleBackColor = true;
			this->m_buttonPause->Click += gcnew System::EventHandler(this, &MainForm::m_buttonPause_Click);
			// 
			// m_buttonStop
			// 
			this->m_buttonStop->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->m_buttonStop->Location = System::Drawing::Point(117, 5);
			this->m_buttonStop->Name = L"m_buttonStop";
			this->m_buttonStop->Size = System::Drawing::Size(51, 23);
			this->m_buttonStop->TabIndex = 2;
			this->m_buttonStop->Text = L"#";
			this->m_buttonStop->UseVisualStyleBackColor = true;
			this->m_buttonStop->Click += gcnew System::EventHandler(this, &MainForm::m_buttonStop_Click);
			// 
			// m_buttonPrev
			// 
			this->m_buttonPrev->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->m_buttonPrev->Location = System::Drawing::Point(174, 5);
			this->m_buttonPrev->Name = L"m_buttonPrev";
			this->m_buttonPrev->Size = System::Drawing::Size(51, 23);
			this->m_buttonPrev->TabIndex = 3;
			this->m_buttonPrev->Text = L"<<";
			this->m_buttonPrev->UseVisualStyleBackColor = true;
			this->m_buttonPrev->Click += gcnew System::EventHandler(this, &MainForm::m_buttonPrev_Click);
			// 
			// m_buttonNext
			// 
			this->m_buttonNext->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->m_buttonNext->Location = System::Drawing::Point(231, 5);
			this->m_buttonNext->Name = L"m_buttonNext";
			this->m_buttonNext->Size = System::Drawing::Size(52, 23);
			this->m_buttonNext->TabIndex = 4;
			this->m_buttonNext->Text = L">>";
			this->m_buttonNext->UseVisualStyleBackColor = true;
			this->m_buttonNext->Click += gcnew System::EventHandler(this, &MainForm::m_buttonNext_Click);
			// 
			// m_tablePlayer
			// 
			this->m_tablePlayer->AutoSize = true;
			this->m_tablePlayer->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->m_tablePlayer->ColumnCount = 1;
			this->m_tablePlayer->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				100)));
			this->m_tablePlayer->Controls->Add(this->m_tableButtons, 0, 1);
			this->m_tablePlayer->Controls->Add(this->m_listPlay, 0, 0);
			this->m_tablePlayer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->m_tablePlayer->Location = System::Drawing::Point(0, 0);
			this->m_tablePlayer->Margin = System::Windows::Forms::Padding(15);
			this->m_tablePlayer->Name = L"m_tablePlayer";
			this->m_tablePlayer->RowCount = 2;
			this->m_tablePlayer->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->m_tablePlayer->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->m_tablePlayer->Size = System::Drawing::Size(292, 469);
			this->m_tablePlayer->TabIndex = 0;
			// 
			// m_listPlay
			// 
			this->m_listPlay->AllowDrop = true;
			this->m_listPlay->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->m_listPlay->FormattingEnabled = true;
			this->m_listPlay->ItemHeight = 12;
			this->m_listPlay->Location = System::Drawing::Point(3, 3);
			this->m_listPlay->Name = L"m_listPlay";
			this->m_listPlay->Size = System::Drawing::Size(286, 424);
			this->m_listPlay->TabIndex = 3;
			this->m_listPlay->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::m_listPlay_SelectedIndexChanged);
			this->m_listPlay->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &MainForm::m_listPlay_DragDrop);
			this->m_listPlay->DoubleClick += gcnew System::EventHandler(this, &MainForm::m_buttonPlay_Click);
			this->m_listPlay->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &MainForm::m_listPlay_DragEnter);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(292, 469);
			this->Controls->Add(this->m_tablePlayer);
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->Text = L"Sipri Mp3 Player";
			this->m_tableButtons->ResumeLayout(false);
			this->m_tablePlayer->ResumeLayout(false);
			this->m_tablePlayer->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void m_buttonPlay_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void m_buttonPause_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void m_buttonStop_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void m_buttonPrev_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void m_buttonNext_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void m_listPlay_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e);
	private: System::Void m_listPlay_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e);
	private: System::Void m_listPlay_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	};
}
