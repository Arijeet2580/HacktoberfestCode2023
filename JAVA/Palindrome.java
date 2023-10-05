public class Palindrome {
    public static void main(String[] args) {
        String input = "radar"; // change input
        
        if (isPalindrome(input)) {
            System.out.println(input + " is palindrome.");
        } else {
            System.out.println(input + " not palindrome.");
        }
    }

    public static boolean isPalindrome(String str) {
        str = str.replaceAll("[^a-zA-Z0-9]", "").toLowerCase(); // remove character non-alphanumeric & change to lower case
        int left = 0;
        int right = str.length() - 1;

        while (left < right) {
            if (str.charAt(left) != str.charAt(right)) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
}
