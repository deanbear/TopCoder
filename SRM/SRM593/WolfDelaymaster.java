// BEGIN CUT HERE

// END CUT HERE
import java.util.regex.Matcher;
import java.util.regex.Pattern;
public class WolfDelaymaster {
	Pattern pattern = Pattern.compile("((w+)(o+)(l+)(f+)+?)"); 
    public String check(String str) {
    	Matcher matcher = pattern.matcher(str);
    	int count = 0;
    	while(matcher.find()) {
    		count += matcher.group().length();
    		if(! (matcher.group(2).length() == matcher.group(3).length()
    				&& matcher.group(3).length() == matcher.group(4).length()
    				&& matcher.group(4).length() == matcher.group(5).length())) {
    			return "INVALID";
    		}
    	}
    	if(count == str.length()) {
    		 return "VALID";
    	} else { 
    		return "INVALID";
    	}
		
	}
}
