package snake; //toplista tartalom

import java.util.ArrayList;
import javax.swing.table.AbstractTableModel;
import database.HighScore;

public class HighScoreTableModel extends AbstractTableModel {

    private final ArrayList<HighScore> highScores;
    private final String[] colName = new String[]{"Name", "Score"};

    public HighScoreTableModel(ArrayList<HighScore> highScores) {
        this.highScores = highScores;
    }

    @Override
    public int getRowCount() {
        return highScores.size();
    }

    @Override
    public int getColumnCount() {
        return 2;
    }

    @Override
    public Object getValueAt(int r, int c) {
        HighScore h = highScores.get(r);
        if (c == 0) {
            if (h.name.equals("null") || h.name.equals("")) {
                return "Anonymus";
            }
            return h.name;
        } else if (c == 1) {
            return h.score;
        }
        
        // Ha minden rendben akkor mar korabban return-olunk
        return null;
    }

    @Override
    public String getColumnName(int i) {
        return colName[i];
    }

}
