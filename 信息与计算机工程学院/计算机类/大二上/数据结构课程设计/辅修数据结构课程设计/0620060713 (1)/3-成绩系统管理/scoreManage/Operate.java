package guy.scoreManage;

import java.util.Iterator;
import java.util.LinkedList;

public class Operate {
	
	//定义一个LinkedList 用来存储学生对象
	private GetOneStr gos = new GetOneStr();
	private Menu menu;
	private Student stu;
	
	//增加学生信息
	 public void AddStudent()
	 {
		 LinkedList ll = StoreLl.getL();
		  stu = new Student();
		 
		  System.out.println("输入姓名: ");
		  stu.setName(gos.getStrFromKeyBoard());
		  
		  System.out.println("输入学号: ");
		  stu.setNum(Integer.parseInt(gos.getStrFromKeyBoard()));
		  
		  Score score = new Score();
		  System.out.println("语文成绩: ");
		  score.setChinese(Integer.parseInt(gos.getStrFromKeyBoard()));
		  System.out.println("数学成绩: ");
		  score.setMath(Integer.parseInt(gos.getStrFromKeyBoard()));
		  System.out.println("外语成绩: ");
		  score.setEnglish(Integer.parseInt(gos.getStrFromKeyBoard()));
		  
		  stu.setScore(score);
		  
		  ll.add(stu);
		  StoreLl.setL(ll);
		  System.out.println(ll.size());
		  
		  System.out.println("增加学生完毕,请进行其他操作");
		  menu = new Menu();
		  menu.getMenu();
	 }
	 
	 public void lookMsgByNum()
	 {
		 LinkedList ll = StoreLl.getL();
		 System.out.println("请输入要查看学生的学号: ");
		  int num = Integer.parseInt(gos.getStrFromKeyBoard());
		  Iterator it = ll.iterator();
		  
		  boolean flag = true;
		  
		  while(it.hasNext())
		  {
			  stu = (Student) it.next();
			  if(num == stu.getNum())
			  {
				  flag = false;
				  System.out.println("姓名\t语文成绩\t数学成绩\t外语成绩");
				  System.out.println(stu.getName()+"\t"+stu.getScore().getChinese()+"\t"+stu.getScore().getMath()+"\t"+stu.getScore().getEnglish());
			  }
		  }
		  
		  if(flag)
		  {
			  System.out.println("没有你查找的学号,或学生不存在");
			  lookMsgByNum();
		  }
		  else
		  {
			  System.out.println("查看完毕,请进行其他操作");
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
		 
		 System.out.println("姓名"+"\t"+"总成绩");
		 for(int p=0; p<tempStu.length; p++)
		 {
			 System.out.println(tempStu[p].getName()+"\t"+tempStu[p].getAll());
		 }
		 
		 System.out.println("查看完毕,请进行其他操作");
		 menu = new Menu();
		  menu.getMenu();
	 }

}
