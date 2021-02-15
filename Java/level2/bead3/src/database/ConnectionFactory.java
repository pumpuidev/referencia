package database;   //csatlakozas adatbazishoz

import com.mysql.jdbc.jdbc2.optional.MysqlConnectionPoolDataSource;
import java.sql.Connection;
import java.sql.SQLException;

public class ConnectionFactory {
    private static MysqlConnectionPoolDataSource conn;
    
    public ConnectionFactory() {}
    
    public static Connection getConnection() 
        throws ClassNotFoundException, SQLException{
        if (conn == null) {     
            conn = new MysqlConnectionPoolDataSource();
            conn.setServerName("localhost");
            conn.setPort(3306);
            conn.setDatabaseName("mysql");
            conn.setUser("ernest");
            conn.setPassword("ernest");
        }
        return conn.getPooledConnection().getConnection();
    }
}