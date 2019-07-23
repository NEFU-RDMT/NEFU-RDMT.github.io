package guy.scoreManage;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class GetOneStr {
	
	public String getStrFromKeyBoard()
	{
		BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
		String strLine = null;
		try {
			strLine = in.readLine();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		return strLine;
	}

}
