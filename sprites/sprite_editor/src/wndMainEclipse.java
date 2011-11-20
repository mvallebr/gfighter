package src;
import javax.swing.JFrame;

/*
 * Criado em 21/03/2004
 *
 * Para alterar o gabarito para este arquivo gerado vá para
 * Janela&gt;Preferências&gt;Java&gt;Geração de Códigos&gt;Código e Comentários
 */

/**
 * @author mvalle
 *
 * Para alterar o gabarito para este comentário do tipo gerado vá para
 * Janela&gt;Preferências&gt;Java&gt;Geração de Códigos&gt;Código e Comentários
 */
public class wndMain extends JFrame {

	private javax.swing.JPanel jContentPane = null;

	private javax.swing.JMenuBar jJMenuBar = null;
	private javax.swing.JMenu jMenu = null;
	private javax.swing.JTabbedPane jTabbedPane = null;
	private javax.swing.JMenuItem jMenuItem = null;
	private javax.swing.JMenuItem jMenuItem1 = null;
	private javax.swing.JMenuItem jMenuItem2 = null;
	private javax.swing.JMenu jMenu1 = null;
	private javax.swing.JMenuItem jMenuItem3 = null;
	private javax.swing.JPanel jPanel = null;
	private javax.swing.JPanel jPanel1 = null;
	private javax.swing.JPanel jPanel2 = null;
	private javax.swing.JPanel jPanel3 = null;
	private javax.swing.JSplitPane jSplitPane = null;
	private javax.swing.JPanel jPanel4 = null;
	private javax.swing.JPanel jPanel5 = null;
	private javax.swing.JToolBar jToolBar = null;
	private javax.swing.JButton jButton = null;
	private javax.swing.JButton jButton1 = null;
	private javax.swing.JList jList = null;
	private javax.swing.JPanel jPanel6 = null;
	private javax.swing.JPanel jPanel7 = null;
	private javax.swing.JScrollPane jScrollPane = null;
	private javax.swing.JToolBar jToolBar1 = null;
	private javax.swing.JButton jButton2 = null;
	private javax.swing.JButton jButton3 = null;
	private javax.swing.JToolBar jToolBar2 = null;
	public static void main(String[] args) {
		wndMain m;
		m = new wndMain();
	}
	/**
	 * This is the default constructor
	 */
	public wndMain() {
		super();
		initialize();
	}
	/**
	 * This method initializes this
	 * 
	 * @return void
	 */
	private void initialize() {
		this.setSize(640, 480);
		this.setContentPane(getJContentPane());
	}
	/**
	 * This method initializes jContentPane
	 * 
	 * @return javax.swing.JPanel
	 */
	private javax.swing.JPanel getJContentPane() {
		if (jContentPane == null) {
			jContentPane = new javax.swing.JPanel();
			jContentPane.setLayout(new java.awt.BorderLayout());
			jContentPane.add(getJJMenuBar(), java.awt.BorderLayout.NORTH);
			jContentPane.add(getJTabbedPane(), java.awt.BorderLayout.EAST);
			jContentPane.setComponentOrientation(java.awt.ComponentOrientation.LEFT_TO_RIGHT);
			jContentPane.setPreferredSize(new java.awt.Dimension(640,480));
		}
		return jContentPane;
	}
	/**
	 * This method initializes jJMenuBar
	 * 
	 * @return javax.swing.JMenuBar
	 */
	private javax.swing.JMenuBar getJJMenuBar() {
		if(jJMenuBar == null) {
			jJMenuBar = new javax.swing.JMenuBar();
			jJMenuBar.add(getJMenu());
			jJMenuBar.add(getJMenu1());
			jJMenuBar.setPreferredSize(new java.awt.Dimension(640,30));
			jJMenuBar.setComponentOrientation(java.awt.ComponentOrientation.LEFT_TO_RIGHT);
			jJMenuBar.setAutoscrolls(false);
		}
		return jJMenuBar;
	}
	/**
	 * This method initializes jMenu
	 * 
	 * @return javax.swing.JMenu
	 */
	private javax.swing.JMenu getJMenu() {
		if(jMenu == null) {
			jMenu = new javax.swing.JMenu();
			jMenu.add(getJMenuItem());
			jMenu.add(getJMenuItem1());
			jMenu.add(getJMenuItem2());
			jMenu.setText("Sprite");
			jMenu.setComponentOrientation(java.awt.ComponentOrientation.LEFT_TO_RIGHT);
			jMenu.setHorizontalAlignment(javax.swing.SwingConstants.LEFT);
			jMenu.setPreferredSize(new java.awt.Dimension(50,61));
		}
		return jMenu;
	}
	/**
	 * This method initializes jTabbedPane
	 * 
	 * @return javax.swing.JTabbedPane
	 */
	private javax.swing.JTabbedPane getJTabbedPane() {
		if(jTabbedPane == null) {
			jTabbedPane = new javax.swing.JTabbedPane();
			jTabbedPane.addTab("Actions", null, getJPanel(), null);
			jTabbedPane.addTab("Inputs", null, getJPanel1(), null);
			jTabbedPane.addTab("States", null, getJPanel2(), null);
			jTabbedPane.addTab("Triggers", null, getJPanel3(), null);
			jTabbedPane.setPreferredSize(new java.awt.Dimension(640,400));
			jTabbedPane.setComponentOrientation(java.awt.ComponentOrientation.UNKNOWN);
			jTabbedPane.setOpaque(false);
		}
		return jTabbedPane;
	}
	/**
	 * This method initializes jMenuItem
	 * 
	 * @return javax.swing.JMenuItem
	 */
	private javax.swing.JMenuItem getJMenuItem() {
		if(jMenuItem == null) {			
			jMenuItem = new javax.swing.JMenuItem();
			jMenuItem.setText("Propriedades");
		}
		return jMenuItem;
	}
	/**
	 * This method initializes jMenuItem1
	 * 
	 * @return javax.swing.JMenuItem
	 */
	private javax.swing.JMenuItem getJMenuItem1() {
		if(jMenuItem1 == null) {
			jMenuItem1 = new javax.swing.JMenuItem();
			jMenuItem1.setText("-");
		}
		return jMenuItem1;
	}
	/**
	 * This method initializes jMenuItem2
	 * 
	 * @return javax.swing.JMenuItem
	 */
	private javax.swing.JMenuItem getJMenuItem2() {
		if(jMenuItem2 == null) {
			jMenuItem2 = new javax.swing.JMenuItem();
			jMenuItem2.setText("Sair");
		}
		return jMenuItem2;
	}
	/**
	 * This method initializes jMenu1
	 * 
	 * @return javax.swing.JMenu
	 */
	private javax.swing.JMenu getJMenu1() {
		if(jMenu1 == null) {
			jMenu1 = new javax.swing.JMenu();
			jMenu1.add(getJMenuItem3());
			jMenu1.setText("Ajuda");
		}
		return jMenu1;
	}
	/**
	 * This method initializes jMenuItem3
	 * 
	 * @return javax.swing.JMenuItem
	 */
	private javax.swing.JMenuItem getJMenuItem3() {
		if(jMenuItem3 == null) {
			jMenuItem3 = new javax.swing.JMenuItem();
			jMenuItem3.setText("Sobre");
		}
		return jMenuItem3;
	}
	/**
	 * This method initializes jPanel
	 * 
	 * @return javax.swing.JPanel
	 */
	private javax.swing.JPanel getJPanel() {
		if(jPanel == null) {
			jPanel = new javax.swing.JPanel();
			jPanel.setLayout(new javax.swing.BoxLayout(jPanel, javax.swing.BoxLayout.X_AXIS));
			jPanel.add(getJSplitPane(), null);
		}
		return jPanel;
	}
	/**
	 * This method initializes jPanel1
	 * 
	 * @return javax.swing.JPanel
	 */
	private javax.swing.JPanel getJPanel1() {
		if(jPanel1 == null) {
			jPanel1 = new javax.swing.JPanel();
		}
		return jPanel1;
	}
	/**
	 * This method initializes jPanel2
	 * 
	 * @return javax.swing.JPanel
	 */
	private javax.swing.JPanel getJPanel2() {
		if(jPanel2 == null) {
			jPanel2 = new javax.swing.JPanel();
		}
		return jPanel2;
	}
	/**
	 * This method initializes jPanel3
	 * 
	 * @return javax.swing.JPanel
	 */
	private javax.swing.JPanel getJPanel3() {
		if(jPanel3 == null) {
			jPanel3 = new javax.swing.JPanel();
		}
		return jPanel3;
	}
	/**
	 * This method initializes jSplitPane
	 * 
	 * @return javax.swing.JSplitPane
	 */
	private javax.swing.JSplitPane getJSplitPane() {
		if(jSplitPane == null) {
			jSplitPane = new javax.swing.JSplitPane();
			jSplitPane.setLeftComponent(getJPanel4());
			jSplitPane.setRightComponent(getJPanel5());
		}
		return jSplitPane;
	}
	/**
	 * This method initializes jPanel4
	 * 
	 * @return javax.swing.JPanel
	 */
	private javax.swing.JPanel getJPanel4() {
		if(jPanel4 == null) {
			jPanel4 = new javax.swing.JPanel();
			jPanel4.setLayout(new javax.swing.BoxLayout(jPanel4, javax.swing.BoxLayout.Y_AXIS));
			jPanel4.add(getJToolBar(), null);			
			jPanel4.add(getJList(), null);
			jPanel4.setPreferredSize(new java.awt.Dimension(150,36));
		}
		return jPanel4;
	}
	/**
	 * This method initializes jPanel5
	 * 
	 * @return javax.swing.JPanel
	 */
	private javax.swing.JPanel getJPanel5() {
		if(jPanel5 == null) {
			jPanel5 = new javax.swing.JPanel();
			jPanel5.setLayout(new javax.swing.BoxLayout(jPanel5, javax.swing.BoxLayout.Y_AXIS));
			jPanel5.add(getJPanel6(), null);
			jPanel5.add(getJPanel7(), null);
		}
		return jPanel5;
	}
	/**
	 * This method initializes jToolBar
	 * 
	 * @return javax.swing.JToolBar
	 */
	private javax.swing.JToolBar getJToolBar() {
		if(jToolBar == null) {
			jToolBar = new javax.swing.JToolBar();
			jToolBar.add(getJButton());
			jToolBar.add(getJButton1());
			jToolBar.setPreferredSize(new java.awt.Dimension(100,36));
			jToolBar.setMaximumSize(new java.awt.Dimension(200,36));
		}
		return jToolBar;
	}
	/**
	 * This method initializes jButton
	 * 
	 * @return javax.swing.JButton
	 */
	private javax.swing.JButton getJButton() {
		if(jButton == null) {
			jButton = new javax.swing.JButton();
			jButton.setPreferredSize(new java.awt.Dimension(32,32));
			jButton.setMaximumSize(new java.awt.Dimension(32,32));
			jButton.setIcon(new javax.swing.ImageIcon(getClass().getResource("/images/add.png")));
		}
		return jButton;
	}
	/**
	 * This method initializes jButton1
	 * 
	 * @return javax.swing.JButton
	 */
	private javax.swing.JButton getJButton1() {
		if(jButton1 == null) {
			jButton1 = new javax.swing.JButton();
			jButton1.setPreferredSize(new java.awt.Dimension(32,32));
			jButton1.setMaximumSize(new java.awt.Dimension(32,32));
			jButton1.setIcon(new javax.swing.ImageIcon(getClass().getResource("/images/del03.png")));
		}
		return jButton1;
	}
	/**
	 * This method initializes jList
	 * 
	 * @return javax.swing.JList
	 */
	private javax.swing.JList getJList() {
		if(jList == null) {
			jList = new javax.swing.JList();
			jList.setMaximumSize(new java.awt.Dimension(200,600));
		}
		return jList;
	}
	/**
	 * This method initializes jPanel6
	 * 
	 * @return javax.swing.JPanel
	 */
	private javax.swing.JPanel getJPanel6() {
		if(jPanel6 == null) {
			jPanel6 = new javax.swing.JPanel();
			jPanel6.setPreferredSize(new java.awt.Dimension(640,430));
		}
		return jPanel6;
	}
	/**
	 * This method initializes jPanel7
	 * 
	 * @return javax.swing.JPanel
	 */
	private javax.swing.JPanel getJPanel7() {
		if(jPanel7 == null) {
			jPanel7 = new javax.swing.JPanel();
			jPanel7.setLayout(new javax.swing.BoxLayout(jPanel7, javax.swing.BoxLayout.X_AXIS));
			jPanel7.add(getJScrollPane(), null);
			jPanel7.add(getJToolBar1(), null);
			jPanel7.setPreferredSize(new java.awt.Dimension(640,34));
		}
		return jPanel7;
	}
	/**
	 * This method initializes jScrollPane
	 * 
	 * @return javax.swing.JScrollPane
	 */
	private javax.swing.JScrollPane getJScrollPane() {
		if(jScrollPane == null) {
			jScrollPane = new javax.swing.JScrollPane();
			jScrollPane.setViewportView(getJToolBar2());
			jScrollPane.setPreferredSize(new java.awt.Dimension(470,40));
		}
		return jScrollPane;
	}
	/**
	 * This method initializes jToolBar1
	 * 
	 * @return javax.swing.JToolBar
	 */
	private javax.swing.JToolBar getJToolBar1() {
		if(jToolBar1 == null) {
			jToolBar1 = new javax.swing.JToolBar();
			jToolBar1.add(getJButton2());
			jToolBar1.add(getJButton3());
			jToolBar1.setPreferredSize(new java.awt.Dimension(80,40));
		}
		return jToolBar1;
	}
	/**
	 * This method initializes jButton2
	 * 
	 * @return javax.swing.JButton
	 */
	private javax.swing.JButton getJButton2() {
		if(jButton2 == null) {
			jButton2 = new javax.swing.JButton();
			jButton2.setPreferredSize(new java.awt.Dimension(32,32));
			jButton2.setMaximumSize(new java.awt.Dimension(32,32));
			jButton2.setIcon(new javax.swing.ImageIcon(getClass().getResource("/images/add.png")));
		}
		return jButton2;
	}
	/**
	 * This method initializes jButton3
	 * 
	 * @return javax.swing.JButton
	 */
	private javax.swing.JButton getJButton3() {
		if(jButton3 == null) {
			jButton3 = new javax.swing.JButton();
			jButton3.setPreferredSize(new java.awt.Dimension(32,32));
			jButton3.setMaximumSize(new java.awt.Dimension(32,32));
			jButton3.setIcon(new javax.swing.ImageIcon(getClass().getResource("/images/del03.png")));
		}
		return jButton3;
	}
	/**
	 * This method initializes jToolBar2
	 * 
	 * @return javax.swing.JToolBar
	 */
	private javax.swing.JToolBar getJToolBar2() {
		if(jToolBar2 == null) {
			jToolBar2 = new javax.swing.JToolBar();
		}
		return jToolBar2;
	}
}  //  @jve:visual-info  decl-index=0 visual-constraint="10,10"
