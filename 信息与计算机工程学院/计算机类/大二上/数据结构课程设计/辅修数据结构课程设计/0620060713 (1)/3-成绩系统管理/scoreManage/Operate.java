package guy.scoreManage;

import java.util.Iterator;
import java.util.LinkedList;

public class Operate {
	
	//����һ��LinkedList �����洢ѧ������
	private GetOneStr gos = new GetOneStr();
	private Menu menu;
	private Student stu;
	
	//����ѧ����Ϣ
	 public void AddStudent()
	 {
		 LinkedList ll = StoreLl.getL();
		  stu = new Student();
		 
		  System.out.println("��������: ");
		  stu.setName(gos.getStrFromKeyBoard());
		  
		  System.out.println("����ѧ��: ");
		  stu.setNum(Integer.parseInt(gos.getStrFromKeyBoard()));
		  
		  Score score = new Score();
		  System.out.println("���ĳɼ�: ");
		  score.setChinese(Integer.parseInt(gos.getStrFromKeyBoard()));
		  System.out.println("��ѧ�ɼ�: ");
		  score.setMath(Integer.parseInt(gos.getStrFromKeyBoard()));
		  System.out.println("����ɼ�: ");
		  score.setEnglish(Integer.parseInt(gos.getStrFromKeyBoard()));
		  
		  stu.setScore(score);
		  
		  ll.add(stu);
		  StoreLl.setL(ll);
		  System.out.println(ll.size());
		  
		  System.out.println("����ѧ�����,�������������");
		  menu = new Menu();
		  menu.getMenu();
	 }
	 
	 public void lookMsgByNum()
	 {
		 LinkedList ll = StoreLl.getL();
		 System.out.println("������Ҫ�鿴ѧ����ѧ��: ");
		  int num = Integer.parseInt(gos.getStrFromKeyBoard());
		  Iterator it = ll.iterator();
		  
		  boolean flag = true;
		  
		  while(it.hasNext())
		  {
			  stu = (Student) it.next();
			  if(num == stu.getNum())
			  {
				  flag = false;
				  System.out.println("����\t���ĳɼ�\t��ѧ�ɼ�\t����ɼ�");
				  System.out.println(stu.getName()+"\t"+stu.getScore().getChinese()+"\t"+stu.getScore().getMath()+"\t"+stu.getScore().getEnglish());
			  }
		  }
		  
		  if(flag)
		  {
			  System.out.println("û������ҵ�ѧ��,��ѧ��������");
			  lookMsgByNum();
		  }
		  else
		  {
			  System.out.println("�鿴���,�������������");
				 menu = new Menu();
				  menu.getMenu();
		  }
	 }
	 
	 public void lookAllScore()
	 {
		 LinkedList ll = StoreLl.getL();
		 Student[] tempStu = new Student[ll.size()];
		 
		 for(int i=0; i<ll.size(); i++)
		 {
			 tempStu[i] = (Student) ll.get(i);
		 }
		 
		 for(int i=1; i<tempStu.length; i++)
		 {
				for(int j=0; j<tempStu.length-1; j++)
				{
					if(tempStu[j].getAll()<tempStu[j+1].getAll())
					{
						Student temp = tempStu[j];
						tempStu[j] = tempStu[j+1];
						tempStu[j+1] = temp;
					}
				}
		 }
		 
		 System.out.println("����"+"\t"+"�ܳɼ�");
		 for(int p=0; p<tempStu.length; p++)
		 {
			 System.out.println(tempStu[p].getName()+"\t"+tempStu[p].getAll());
		 }
		 
		 System.out.println("�鿴���,�������������");
		 menu = new Menu();
		  menu.getMenu();
	 }

}
