//
//  DropDownList.h
//  CustomDropDownList
//
//  Created by ESoragoto on 11/20/14.
//
//

#ifndef __CustomDropDownList__DropDownList__
#define __CustomDropDownList__DropDownList__

#pragma once

#include <cocos2d.h>

USING_NS_CC;
NS_CC_BEGIN

namespace CustomDropDownListBox
{
	//������ɫ
	//��ͨ��ɫ(Color4B)
	const auto kDropDownListNormalColor4B = Color4B(128,
		128,
		128,
		255);
	//ѡ����ɫ(Color4B)
	const auto kDropDownListSelectedColor4B = Color4B(200,
		200,
		200,
		255);
	//������ɫ(Color4B)
	const auto kDropDownListHighlightColor4B = Color4B(0,
		0,
		255,
		255);
	//��ͨ��ɫ(Color3B)
	const auto kDropDownListNormalColor3B = Color3B(128,
		128,
		128);
	//ѡ����ɫ(Color3B)
	const auto kDropDownListSelectedColor3B = Color3B(200,
		200,
		200);
	//������ɫ(Color3B)
	const auto kDropDownListHighlightColor3B = Color3B(0,
		0,
		225);
	const auto kColorWhite = Color3B(255,
		255,
		255);

	//��������
	class DropDownList : public Layer
	{
	public:
		DropDownList(Label *label,
			Size show_label_size,
			Size main_menu_cell_size);
		~DropDownList();

		///<summary>
		///��ʼ��
		///</summary>
		void OpenListener();

		///<summary>
		///����ʵ������
		///</summary>
		///<parm name = "*label">����һ��label��ΪĬ����ʾ</parm>
		///<parm name = "size">Ĭ�ϳߴ�</parm>
		static DropDownList * Create(Label *label,
			Size show_label_size,
			Size main_menu_cell_size);

		///<summary>
		///��ȡѡ�ж����string
		///</summary>
		std::string GetString();

		///<summary>
		///��ȡѡ�е�index
		///</summary>
		int GetSelectedIndex();

		///<summary>
		///����ѡ�еĶ���
		///</summary>
		///<parm name = "index">�����indexֵ</parm>
		void SetSelectedIndex(int index);

		///<summary>
		///��ʼ����
		///</summary>
		///<parm name = "*touch">��������</parm>
		///<parm name = "*event">�����¼�</parm>
		virtual bool onTouchBegan(Touch *touch,
			Event *event);

		///<summary>
		///��������
		///</summary>
		///<parm name = "*touch">��������</parm>
		///<parm name = "*event">�����¼�</parm>
		void onTouchEnded(Touch *touch,
			Event *event);

		///<summary>
		///�����µ�Label��ð�������˵�
		///</summary>
		///<parm name = "*label">ð��˵��õ�label�ز�</parm>
		void AddLabel(Label *label);

		///<summary>
		///�����б��е��ѡ��
		///</summary>
		///<parm name = "*sender">������ĵĶ���</parm>
		void OnSelected(Ref *sender);

		///<summary>
		///�ر������б�
		///</summary>
		void OnClose();

		///<summary>
		///�Զ����λ������
		///</summary>
		///<parm name = "*sender">������ĵĶ���</parm>
		void CustomSetPosition(Node *node,
			Point point);

	private:
		Menu *main_menu_;    //����ѡ���б��ļ���
		Label *show_label_;   //����ʾ����label
		std::vector<Label *> select_labels_;   //����ð�������б���label��
		std::vector<LayerColor *> bg_layers_; //�������ñ�����ɫ
		bool is_need_show_menu_; //�Ƿ�����ʾ�������б�
		int last_selected_index_;  //ѡ�������б���index
		Size main_menu_cell_size_;   //�˵��������Size
		Size show_label_size_;  //����ʾ����label��ռ�����

		EventListenerTouchOneByOne *listener_touch_;
	};//class DropDownList : public Layer
}//namespace CustomDropDownListBox
NS_CC_END

#endif //#define __CustomDropDownList__DropDownList__