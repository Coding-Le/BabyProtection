//
//  DropDownList.cpp
//  CustomDropDownList
//
//  Created by ESoragoto on 11/20/14.
//
//


#include "cocos2d.h"
#include "DropDownList.h"

USING_NS_CC;

NS_CC_BEGIN

namespace CustomDropDownListBox {
	DropDownList::DropDownList(Label *label,
		Size show_label_size,
		Size main_menu_cell_size) :
		show_label_(label),
		is_need_show_menu_(false),
		last_selected_index_(0)
	{
		show_label_size_ = show_label_size;
		main_menu_cell_size_ = main_menu_cell_size;

		main_menu_ = Menu::create();
		//        main_menu_->setPosition(Point(show_label_size_.width / 2,
		//                                      show_label_size_.height / 2));
		CustomSetPosition(main_menu_,
			Point(0,
			0));
		main_menu_->setColor(Color3B::WHITE);  //kDropDownListNormalColor3B
		main_menu_->retain();

		//        show_label_->setPosition(Point(show_label_size_.width / 2,
		//                                       show_label_size_.height / 2));
		CustomSetPosition(show_label_,
			Point(0,
			0));
		show_label_->setColor(Color3B::WHITE);

		this->addChild(show_label_);

		this->setContentSize(show_label_size_);
	}//DropDownList::DropDownList

	DropDownList::~DropDownList() {};

	void DropDownList::OpenListener()
	{
		//���Ӵ�������
		listener_touch_ = EventListenerTouchOneByOne::create();
		listener_touch_->onTouchBegan = CC_CALLBACK_2(DropDownList::onTouchBegan,
			this);
		listener_touch_->onTouchEnded = CC_CALLBACK_2(DropDownList::onTouchEnded,
			this);
		_eventDispatcher->addEventListenerWithSceneGraphPriority(listener_touch_,
			this);
		//���������������Ϣ
		log("listener ready");
	}//DropDownList::OpenListener

	DropDownList *DropDownList::Create(Label *label,
		Size show_label_size,
		Size main_menu_cell_size)
	{
		auto *list = new DropDownList(label,
			show_label_size,
			main_menu_cell_size);
		list->autorelease();
		return list;
	}//*DropDownList::create

	std::string DropDownList::GetString()
	{
		return show_label_->getString();
	}//DropDownList::GetString

	int DropDownList::GetSelectedIndex()
	{
		return last_selected_index_;
	}//DropDownList::GetSelectedIndex

	void DropDownList::SetSelectedIndex(int index)
	{
		last_selected_index_ = index;//��ȡ��ѡ�ж����index����

		//��������Ԫ��
		for (int i = 0, j = (int)select_labels_.size(); i < j; i++)
		{
			//����index��ֵ�ж��Ƿ��Ǳ�ѡ�еĶ���
			if (last_selected_index_ == i)
			{//����Ǳ�ѡ�еĶ����������䱳��ɫΪ��ѡ�е���ɫ�����Ҵ��ظö����stringֵ(��ʾ������)
				bg_layers_[i]->setColor(Color3B::YELLOW);
				show_label_->setString(select_labels_[i]->getString());
			}
			else
			{//������Ǳ�ѡ�еĶ����������ұ���ɫΪ��ͨ��ɫ
				bg_layers_[i]->setColor(Color3B::YELLOW);
			}
		}
	}//DropDownList::SetSelectedIndex

	bool DropDownList::onTouchBegan(Touch *touch,
		Event *event)
	{
		//��ȡ���λ��
		auto location_in_view = touch->getLocationInView();
		auto location = Director::getInstance()->convertToGL(location_in_view);

		//����̨����������λ��
		log("BEGAN----------");
		log("location: %f, %f",
			location.x,
			location.y);

		//�жϲ˵��Ƿ���Ҫ��ʾ
		if (false == is_need_show_menu_)
		{//�˵�����Ҫ��ʾ�ĳ���
			Rect show_rect;
			show_rect.origin = this->getPosition();//��ȡ��ʾ����Position
			show_rect.size = show_label_size_;//��ȡ��ʾ����Size

			//���������̨
			log("rect----------");
			log("location: %f, %f",
				show_rect.origin.x,
				show_rect.origin.y);
			log("size: %f, %f",
				show_rect.size.width,
				show_rect.size.height);

			//�жϴ������Position�Ƿ�����ʾ����
			if (show_rect.containsPoint(location))
			{//���λ������ʾ���ڵĳ��ϣ�����Ҫ��ʾ�˵�
				is_need_show_menu_ = true;//����״̬Ϊ��Ҫ��ʾ�˵�
				return true;
			}
		}
		else
		{//�˵���Ҫ��ʾ�ĳ���(���������Ѿ���ʾ�˲˵���״̬)
			Rect list_rect;
			list_rect.origin = this->getPosition();
			list_rect.size = show_label_size_;

			//�жϴ������Position�Ƿ�����ʾ����
			if (!list_rect.containsPoint(location))
			{//���λ�ò�����ʾ���ڵĳ���
				OnClose();//�ر�main_menu_
			}
		}

		return false;
	}//DropDownList::onTouchBegan

	void DropDownList::onTouchEnded(cocos2d::Touch *touch,
		cocos2d::Event *event)
	{
		//�ж��Ƿ���Ҫ��ʾ�˵�
		if (true == is_need_show_menu_)
		{
			//����Ԫ������ɫ
			for (int i = 0, j = (int)select_labels_.size(); i < j; i++)
			{
				//�жϳ���һ��ѡ��Ķ���
				if (last_selected_index_ == i)
				{//��ǰԪ�����ϴ�ѡ�еĶ���ĳ���
					bg_layers_[i]->setColor(Color3B::WHITE);//��ɫ����
				}
				else
				{//��ͨԪ�صĳ���
					bg_layers_[i]->setColor(Color3B::WHITE);
				}
			}
			//���ӵ���������ʾ
			addChild(main_menu_);
		}
	}//DropDownList::onTouchEnded

	void DropDownList::AddLabel(Label *label)
	{
		auto *normal_color = LayerColor::create(kDropDownListNormalColor4B,
			main_menu_cell_size_.width,
			main_menu_cell_size_.height);
		auto *pSelectedColor = LayerColor::create(kDropDownListSelectedColor4B,
			main_menu_cell_size_.width,
			main_menu_cell_size_.height);
		//std::vector::push_back
		bg_layers_.push_back(normal_color);
		select_labels_.push_back(label);

		//����main_menu_��Ԫ��
		//        auto ite = MenuItemLabel::create(<#cocos2d::Node *label#>, <#const ccMenuCallback &callback#>)
		//        MenuItemSprite::Create(<#cocos2d::Label *label#>, <#cocos2d::Size show_label_size#>, <#cocos2d::Size main_menu_cell_size#>)
		//        MenuItemSprite::create()
		auto item = MenuItemSprite::create(normal_color,
			pSelectedColor,
			NULL,
			this,
			SEL_MenuHandler(&DropDownList::OnSelected));

		label->setPosition(Point(main_menu_cell_size_.width / 2,
			main_menu_cell_size_.height / 2));
		item->addChild(label);
		//select_labels_��������select_labels_.size()��ʾ�����Ԫ�صĸ���
		item->setTag((int)select_labels_.size() - 1);
		item->setPosition(0,
			-(int)select_labels_.size() * main_menu_cell_size_.height);
		main_menu_->addChild(item);
	}//DropDownList::AddLabel

	void DropDownList::OnSelected(Ref *sender)
	{
		auto item = dynamic_cast<MenuItem *>(sender);

		if (item)
		{
			last_selected_index_ = item->getTag();
			show_label_->setString(select_labels_[item->getTag()]->getString());
		}
		OnClose();
	}//DropDownList::OnSelected

	void DropDownList::OnClose()
	{
		removeChild(main_menu_,
			true);
		is_need_show_menu_ = false;
	}//DropDownList::OnClose

	//�ֶ�дPosition���÷������������ê��
	void DropDownList::CustomSetPosition(Node *node,
		Point point)
	{
		node->setPosition(Point(point.x + show_label_size_.width / 2,
			point.y + show_label_size_.height / 2));
	}//DropDownList::CustomSetPosition
}//namespace CustomDropDownListBox

NS_CC_END