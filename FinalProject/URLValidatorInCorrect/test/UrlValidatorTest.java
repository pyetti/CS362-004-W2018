
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!

public class UrlValidatorTest extends TestCase {

	public UrlValidatorTest(String testName) {
		super(testName);
	}

	public void testManualTest() {
		System.out.println("MANUAL TESTING FAILURES - DISALLOW ALL SCHEMES");
		UrlValidator urlValidator = new UrlValidator();
		if (!urlValidator.isValid("http://www.google.com")) {
			System.out.println("FAILED: http://www.google.com\n");
		}

	}

	public void testYourFirstPartition() {
		
		UrlValidator urlValidator = new UrlValidator();
		
		int i, j, k;
		
		int[] ind = {0, 0, 0, 0, 0};
				
		String[] schemesList = {
				"http://", "ftp://", "h3t://", "https://"
				},
				authoritiesList = {
				"www.google.com", "www.espn.com", "jsfiddle.net", "oregonstate.edu"
				},
				portsList = {
				":80", ":22", ":1600", ":1"
				},
				pathsList = {
				"/index", "/pages/about/", "/", "/path/Home"
				},
				queriesList = {
				"?roses=red", "?violets=blue", "?roses=red&violets=blue", "?a=1&b=2&c=3"
				};
		
		String[][] listList = {
				schemesList, authoritiesList, portsList, pathsList, queriesList
		};
				
		List<Boolean> results = new ArrayList<Boolean>();
		//StringBuilder testURL = new StringBuilder(scheme);
		for (i = 0; i < 4; i++) {
			String scheme;
			for (j = 0; j < 5; j++) {
				ind[j] = i;
				scheme = listList[0][ind[0]];
				StringBuilder testURL = new StringBuilder(scheme);
				for (k = 1; k < 5; k++) {
	    		    testURL.append(listList[k][ind[k]]);
				}
    			boolean isValid = urlValidator.isValid(testURL.toString());
    			if (!isValid) {
    				System.out.println("FAILED: " + testURL);
    			}
    			results.add(isValid);
    			ind[j] = 0;
			}
		}
	}

    public void testUrlPartsArray(UrlValidator urlValidator, String[] testArray, int index, boolean expected) {
        
        String[] urlParts = { "https://", "www.google.com", "", "/search", "?q=google" };
        int i, j;
        
		for (i = 0; i < testArray.length; i++) {
            urlParts[index] = testArray[i];
            StringBuilder testURL = new StringBuilder(urlParts[0]);
			for (j = 1; j < 5; j++) {
                testURL.append(urlParts[j]);
			}
			
			boolean isValid = urlValidator.isValid(testURL.toString());
			assertEquals(isValid, expected);
			/*if (isValid)
			{
				System.out.println("Passed.");
			}
			
			else
			{
				System.out.println("Failed.");
			}*/
			
		}
	}

	public void unitTestsForAllParts() {
		
		UrlValidator urlValidator = new UrlValidator();
				
		String[] goodSchemes = {
				"http://", "ftp://", "h3t://", "https://", "HTTP://", "HTTPS://", "FTP://"
                },
                badSchemes = {
                 "https:/", "https:\\\\", "https;//", " https://", "https//", "h1n1://", "ho:dor//"
				},
				goodAuthorities = {
				"www.google.com", "www.espn.com", "jsfiddle.net", "oregonstate.edu"
				},
                badAuthorities = {
				"ww.google.com", "wwww.espn.com", "jsfiddle.not", "oregonstate..edu"
				},
				goodPorts = {
				":80", ":22", ":1600", ":1"
				},
                badPorts = {
				":8000000000000", ":2:2", ";1600", "1:", ":3.14159"
				},
				goodPaths = {
				"/index", "/pages/about/", "/", "/path/Home"
				},
                badPaths = {
				"/index\\", "/pages.com/about/", "./", "::/path/Home"
				},
				goodQueries = {
				"?roses=red", "?violets=blue", "?roses=red&violets=blue", "?a=1&b=2&c=3"
				},
                badQueries = {
				"?roses==red", "?birdman!=beat", "&question=ampersand", "#one=two",
                "?planes&trains&automobiles", "&i?am=groot"
				};
                
		System.out.println("Testing urls with valid schemes...");
        testUrlPartsArray(urlValidator, goodSchemes, 0, true);
        
        System.out.println("Testing urls with invalid schemes...");
        testUrlPartsArray(urlValidator, badSchemes, 0, false);
        
        System.out.println("Testing urls with valid authorities...");
        testUrlPartsArray(urlValidator, goodAuthorities, 1, true);
        
        System.out.println("Testing urls with invalid authorities...");
        testUrlPartsArray(urlValidator, badAuthorities, 1, false);
        
        System.out.println("Testing urls with valid ports...");
        testUrlPartsArray(urlValidator, goodPorts, 2, true);
        
        System.out.println("Testing urls with invalid ports...");
        testUrlPartsArray(urlValidator, badPorts, 2, false);
        
        System.out.println("Testing urls with valid paths...");
        testUrlPartsArray(urlValidator, goodPaths, 3, true);
        
        System.out.println("Testing urls with invalid paths...");
        testUrlPartsArray(urlValidator, badPaths, 3, false);
        
        System.out.println("Testing urls with valid queries...");
        testUrlPartsArray(urlValidator, goodQueries, 4, true);
        
        System.out.println("Testing urls with invalid queries...");
        testUrlPartsArray(urlValidator, badQueries, 4, false);
	}

	public void testIsValid() {
		System.out.println("UNIT TESTING FAILURES - ALLOW ALL SCHEMES");
		UrlValidator urlValidator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		
		List<Boolean> results = testURLs(urlValidator, "http://");
		results.addAll(testURLs(urlValidator, "ftp://"));
		results.addAll(testURLs(urlValidator, "h3t://"));
		for (boolean b : results) {
			assertTrue(b);
		}
	}

	private List<Boolean> testURLs(UrlValidator urlValidator, String scheme) {
		List<Boolean> results = new ArrayList<Boolean>();
		StringBuilder baseURL = new StringBuilder(scheme);
		for (String part : VALID_PARTS) {
			baseURL.append(part);
			boolean isValid = urlValidator.isValid(baseURL.toString());
			if (!isValid) {
				System.out.println("FAILED: " + baseURL);
			}
			results.add(isValid);
		}
		return results;
	}

	private static String[] VALID_PARTS = { 
			"www.google.com", ":80", "/", "subfolder", "?", "query", "=queryParameter" 
	};

}
