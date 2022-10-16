// Problem statement
/*
Anagram--> The dictionary meaning of the word anagram is a word or phrase formed by rearranging the letters.
eg: HEART = EARTH
Approach:
First check the length, if not equal then discard it otherwise apply logic.
Pick a character from one list and check it with other if it is not visited then add it to list and check accordingly.
*/

import java.util.*;
public class Anagrams {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		String a = sc.next();  // Add first string
		String b = sc.next();  // Add second string
		boolean isAnagram = false;
		boolean visited[] = new boolean[b.length()];

		if(a.length() == b.length()) {

		for(int i = 0; i < a.length(); i++)
		{
			char c= a.charAt(i);  // Pick a character from a
			isAnagram = false;
			for(int j = 0; j < b.length(); j++)
			{
				if(b.charAt(j) == c && !visited[j])
				{
					visited[j] = true;
					isAnagram = true;
					break;
				}
			}
			if(!isAnagram)
				break;
		}
		} 
		if(isAnagram)
			System.out.println("anagram");
		else
			System.out.println("not anagram");

            sc.close();
	}

}
