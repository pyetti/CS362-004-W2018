
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
		// You can use this function to implement your First Partition testing

	}

	public void testYourSecondPartition() {
		// You can use this function to implement your Second Partition testing

	}
	// You need to create more test cases for your Partitions if you need to

	public void testIsValid() {
		System.out.println("UNIT TESTING FAILURES - ALLOW ALL SCHEMES");
		UrlValidator urlValidator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		testHttp(urlValidator);
	}

	private void testHttp(UrlValidator urlValidator) {
		boolean[] results = new boolean[VALID_PARTS.length];
		StringBuilder baseURL = new StringBuilder("http://");
		for (int part = 0; part < VALID_PARTS.length; part++) {
			baseURL.append(VALID_PARTS[part]);
			boolean isValid = urlValidator.isValid(baseURL.toString());
			if (!isValid) {
				System.out.println("FAILED: " + baseURL);
			}
			results[part] = isValid;
		}
		
		for (boolean b : results) {
			assertTrue(b);
		}
	}
	
	private static String[] VALID_PARTS = {
			"www.google.com", ":80", "/", "subfolder", "?", "query", "=queryParameter"
	};

}
