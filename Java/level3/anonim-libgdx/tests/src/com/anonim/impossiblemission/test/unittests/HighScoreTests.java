package com.anonim.impossiblemission.test.unittests;

import com.anonim.impossiblemission.database.HighScore;
import org.junit.Test;
import static org.junit.Assert.*;

public class HighScoreTests {
    HighScore highScore1 = new HighScore("A", 10, -1);
    HighScore highScore2 = new HighScore("A", 5, -1);
    HighScore highScore3 = new HighScore("B", 10, -1);
    HighScore highScore4 = new HighScore("A", 10, -1);

    @Test
    public void compareToTest() {
        assertEquals(highScore1.compareTo(highScore2), 1);
        assertEquals(highScore2.compareTo(highScore1), -1);
        assertEquals(highScore1.compareTo(highScore1), 0);
        assertEquals(highScore1.compareTo(highScore4), 0);
        assertEquals(highScore1.compareTo(highScore3), -1);
    }
}
