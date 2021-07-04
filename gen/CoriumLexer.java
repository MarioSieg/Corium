// Generated from /home/mario/Documents/Corium/Corium/Parser/CoriumLexer.g4 by ANTLR 4.9.1
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class CoriumLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.9.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		BOOL=1, CHAR=2, FLOAT=3, FUN=4, INT=5, LET=6, INT_LITERAL_DEC=7, INT_LITERAL_HEX=8, 
		INT_LITERAL_OCT=9, INT_LITERAL_BIN=10, FLOAT_LITERAL_DEC=11, FLOAT_LITERAL_HEX=12, 
		BOOL_LITERAL=13, CHAR_LITERAL=14, STRING_LITERAL=15, LPAREN=16, RPAREN=17, 
		LBRACE=18, RBRACE=19, LBRACK=20, RBRACK=21, SEMI=22, COMMA=23, DOT=24, 
		ASSIGN=25, IDENT=26, WHITESPACE=27, SINGLE_LINE_COMMENT=28, MULTI_LINE_COMMENT=29;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"BOOL", "CHAR", "FLOAT", "FUN", "INT", "LET", "INT_LITERAL_DEC", "INT_LITERAL_HEX", 
			"INT_LITERAL_OCT", "INT_LITERAL_BIN", "FLOAT_LITERAL_DEC", "FLOAT_LITERAL_HEX", 
			"BOOL_LITERAL", "CHAR_LITERAL", "STRING_LITERAL", "LPAREN", "RPAREN", 
			"LBRACE", "RBRACE", "LBRACK", "RBRACK", "SEMI", "COMMA", "DOT", "ASSIGN", 
			"IDENT", "WHITESPACE", "SINGLE_LINE_COMMENT", "MULTI_LINE_COMMENT", "EscapeSequence", 
			"ExponentPart", "HexDigits", "HexDigit", "Digits", "LetterOrDigit", "Letter"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'bool'", "'char'", "'float'", "'fun'", "'int'", "'let'", null, 
			null, null, null, null, null, null, null, null, "'('", "')'", "'{'", 
			"'}'", "'['", "']'", "';'", "','", "'.'", "'='"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "BOOL", "CHAR", "FLOAT", "FUN", "INT", "LET", "INT_LITERAL_DEC", 
			"INT_LITERAL_HEX", "INT_LITERAL_OCT", "INT_LITERAL_BIN", "FLOAT_LITERAL_DEC", 
			"FLOAT_LITERAL_HEX", "BOOL_LITERAL", "CHAR_LITERAL", "STRING_LITERAL", 
			"LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACK", "RBRACK", "SEMI", "COMMA", 
			"DOT", "ASSIGN", "IDENT", "WHITESPACE", "SINGLE_LINE_COMMENT", "MULTI_LINE_COMMENT"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}


	public CoriumLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "CoriumLexer.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\37\u0153\b\1\4\2"+
		"\t\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4"+
		"\13\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22"+
		"\t\22\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31"+
		"\t\31\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t"+
		" \4!\t!\4\"\t\"\4#\t#\4$\t$\4%\t%\3\2\3\2\3\2\3\2\3\2\3\3\3\3\3\3\3\3"+
		"\3\3\3\4\3\4\3\4\3\4\3\4\3\4\3\5\3\5\3\5\3\5\3\6\3\6\3\6\3\6\3\7\3\7\3"+
		"\7\3\7\3\b\3\b\3\b\5\bk\n\b\3\b\6\bn\n\b\r\b\16\bo\3\b\5\bs\n\b\5\bu\n"+
		"\b\3\t\3\t\3\t\3\t\7\t{\n\t\f\t\16\t~\13\t\3\t\5\t\u0081\n\t\3\n\3\n\3"+
		"\n\7\n\u0086\n\n\f\n\16\n\u0089\13\n\3\n\3\n\7\n\u008d\n\n\f\n\16\n\u0090"+
		"\13\n\3\n\5\n\u0093\n\n\3\13\3\13\3\13\3\13\7\13\u0099\n\13\f\13\16\13"+
		"\u009c\13\13\3\13\5\13\u009f\n\13\3\13\5\13\u00a2\n\13\3\f\3\f\3\f\5\f"+
		"\u00a7\n\f\3\f\3\f\5\f\u00ab\n\f\3\f\5\f\u00ae\n\f\3\f\3\f\3\f\5\f\u00b3"+
		"\n\f\3\r\3\r\3\r\3\r\5\r\u00b9\n\r\3\r\5\r\u00bc\n\r\3\r\3\r\5\r\u00c0"+
		"\n\r\3\r\3\r\5\r\u00c4\n\r\3\r\3\r\3\16\3\16\3\16\3\16\3\16\3\16\3\16"+
		"\3\16\3\16\5\16\u00d1\n\16\3\17\3\17\3\17\5\17\u00d6\n\17\3\17\3\17\3"+
		"\20\3\20\3\20\5\20\u00dd\n\20\3\20\3\20\3\21\3\21\3\22\3\22\3\23\3\23"+
		"\3\24\3\24\3\25\3\25\3\26\3\26\3\27\3\27\3\30\3\30\3\31\3\31\3\32\3\32"+
		"\3\33\3\33\7\33\u00f7\n\33\f\33\16\33\u00fa\13\33\3\34\6\34\u00fd\n\34"+
		"\r\34\16\34\u00fe\3\34\3\34\3\35\3\35\7\35\u0105\n\35\f\35\16\35\u0108"+
		"\13\35\3\35\3\35\3\36\3\36\3\36\3\36\7\36\u0110\n\36\f\36\16\36\u0113"+
		"\13\36\3\36\3\36\3\36\3\36\3\36\3\37\3\37\3\37\3\37\5\37\u011e\n\37\3"+
		"\37\5\37\u0121\n\37\3\37\3\37\3\37\6\37\u0126\n\37\r\37\16\37\u0127\3"+
		"\37\3\37\3\37\3\37\3\37\5\37\u012f\n\37\3 \3 \5 \u0133\n \3 \3 \3!\3!"+
		"\3!\7!\u013a\n!\f!\16!\u013d\13!\3!\5!\u0140\n!\3\"\3\"\3#\3#\7#\u0146"+
		"\n#\f#\16#\u0149\13#\3#\5#\u014c\n#\3$\3$\5$\u0150\n$\3%\3%\3\u0111\2"+
		"&\3\3\5\4\7\5\t\6\13\7\r\b\17\t\21\n\23\13\25\f\27\r\31\16\33\17\35\20"+
		"\37\21!\22#\23%\24\'\25)\26+\27-\30/\31\61\32\63\33\65\34\67\359\36;\37"+
		"=\2?\2A\2C\2E\2G\2I\2\3\2\31\3\2\63;\4\2ZZzz\5\2\62;CHch\6\2\62;CHaac"+
		"h\4\2EEee\3\2\629\4\2\629aa\4\2DDdd\3\2\62\63\4\2\62\63aa\4\2NNnn\4\2"+
		"RRrr\4\2--//\6\2\f\f\17\17))^^\6\2\f\f\17\17$$^^\4\2\13\f\17\17\4\2\f"+
		"\f\17\17\n\2$$))^^ddhhppttvv\3\2\62\65\4\2GGgg\3\2\62;\4\2\62;aa\4\2C"+
		"\\c|\2\u0172\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2\2\t\3\2\2\2\2\13\3\2"+
		"\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21\3\2\2\2\2\23\3\2\2\2\2\25\3\2\2\2\2"+
		"\27\3\2\2\2\2\31\3\2\2\2\2\33\3\2\2\2\2\35\3\2\2\2\2\37\3\2\2\2\2!\3\2"+
		"\2\2\2#\3\2\2\2\2%\3\2\2\2\2\'\3\2\2\2\2)\3\2\2\2\2+\3\2\2\2\2-\3\2\2"+
		"\2\2/\3\2\2\2\2\61\3\2\2\2\2\63\3\2\2\2\2\65\3\2\2\2\2\67\3\2\2\2\29\3"+
		"\2\2\2\2;\3\2\2\2\3K\3\2\2\2\5P\3\2\2\2\7U\3\2\2\2\t[\3\2\2\2\13_\3\2"+
		"\2\2\rc\3\2\2\2\17t\3\2\2\2\21v\3\2\2\2\23\u0082\3\2\2\2\25\u0094\3\2"+
		"\2\2\27\u00b2\3\2\2\2\31\u00b4\3\2\2\2\33\u00d0\3\2\2\2\35\u00d2\3\2\2"+
		"\2\37\u00d9\3\2\2\2!\u00e0\3\2\2\2#\u00e2\3\2\2\2%\u00e4\3\2\2\2\'\u00e6"+
		"\3\2\2\2)\u00e8\3\2\2\2+\u00ea\3\2\2\2-\u00ec\3\2\2\2/\u00ee\3\2\2\2\61"+
		"\u00f0\3\2\2\2\63\u00f2\3\2\2\2\65\u00f4\3\2\2\2\67\u00fc\3\2\2\29\u0102"+
		"\3\2\2\2;\u010b\3\2\2\2=\u012e\3\2\2\2?\u0130\3\2\2\2A\u0136\3\2\2\2C"+
		"\u0141\3\2\2\2E\u0143\3\2\2\2G\u014f\3\2\2\2I\u0151\3\2\2\2KL\7d\2\2L"+
		"M\7q\2\2MN\7q\2\2NO\7n\2\2O\4\3\2\2\2PQ\7e\2\2QR\7j\2\2RS\7c\2\2ST\7t"+
		"\2\2T\6\3\2\2\2UV\7h\2\2VW\7n\2\2WX\7q\2\2XY\7c\2\2YZ\7v\2\2Z\b\3\2\2"+
		"\2[\\\7h\2\2\\]\7w\2\2]^\7p\2\2^\n\3\2\2\2_`\7k\2\2`a\7p\2\2ab\7v\2\2"+
		"b\f\3\2\2\2cd\7n\2\2de\7g\2\2ef\7v\2\2f\16\3\2\2\2gu\7\62\2\2hr\t\2\2"+
		"\2ik\5E#\2ji\3\2\2\2jk\3\2\2\2ks\3\2\2\2ln\7a\2\2ml\3\2\2\2no\3\2\2\2"+
		"om\3\2\2\2op\3\2\2\2pq\3\2\2\2qs\5E#\2rj\3\2\2\2rm\3\2\2\2su\3\2\2\2t"+
		"g\3\2\2\2th\3\2\2\2u\20\3\2\2\2vw\7\62\2\2wx\t\3\2\2x\u0080\t\4\2\2y{"+
		"\t\5\2\2zy\3\2\2\2{~\3\2\2\2|z\3\2\2\2|}\3\2\2\2}\177\3\2\2\2~|\3\2\2"+
		"\2\177\u0081\t\4\2\2\u0080|\3\2\2\2\u0080\u0081\3\2\2\2\u0081\22\3\2\2"+
		"\2\u0082\u0083\7\62\2\2\u0083\u0087\t\6\2\2\u0084\u0086\7a\2\2\u0085\u0084"+
		"\3\2\2\2\u0086\u0089\3\2\2\2\u0087\u0085\3\2\2\2\u0087\u0088\3\2\2\2\u0088"+
		"\u008a\3\2\2\2\u0089\u0087\3\2\2\2\u008a\u0092\t\7\2\2\u008b\u008d\t\b"+
		"\2\2\u008c\u008b\3\2\2\2\u008d\u0090\3\2\2\2\u008e\u008c\3\2\2\2\u008e"+
		"\u008f\3\2\2\2\u008f\u0091\3\2\2\2\u0090\u008e\3\2\2\2\u0091\u0093\t\7"+
		"\2\2\u0092\u008e\3\2\2\2\u0092\u0093\3\2\2\2\u0093\24\3\2\2\2\u0094\u0095"+
		"\7\62\2\2\u0095\u0096\t\t\2\2\u0096\u009e\t\n\2\2\u0097\u0099\t\13\2\2"+
		"\u0098\u0097\3\2\2\2\u0099\u009c\3\2\2\2\u009a\u0098\3\2\2\2\u009a\u009b"+
		"\3\2\2\2\u009b\u009d\3\2\2\2\u009c\u009a\3\2\2\2\u009d\u009f\t\n\2\2\u009e"+
		"\u009a\3\2\2\2\u009e\u009f\3\2\2\2\u009f\u00a1\3\2\2\2\u00a0\u00a2\t\f"+
		"\2\2\u00a1\u00a0\3\2\2\2\u00a1\u00a2\3\2\2\2\u00a2\26\3\2\2\2\u00a3\u00a4"+
		"\5E#\2\u00a4\u00a6\7\60\2\2\u00a5\u00a7\5E#\2\u00a6\u00a5\3\2\2\2\u00a6"+
		"\u00a7\3\2\2\2\u00a7\u00ab\3\2\2\2\u00a8\u00a9\7\60\2\2\u00a9\u00ab\5"+
		"E#\2\u00aa\u00a3\3\2\2\2\u00aa\u00a8\3\2\2\2\u00ab\u00ad\3\2\2\2\u00ac"+
		"\u00ae\5? \2\u00ad\u00ac\3\2\2\2\u00ad\u00ae\3\2\2\2\u00ae\u00b3\3\2\2"+
		"\2\u00af\u00b0\5E#\2\u00b0\u00b1\5? \2\u00b1\u00b3\3\2\2\2\u00b2\u00aa"+
		"\3\2\2\2\u00b2\u00af\3\2\2\2\u00b3\30\3\2\2\2\u00b4\u00b5\7\62\2\2\u00b5"+
		"\u00bf\t\3\2\2\u00b6\u00b8\5A!\2\u00b7\u00b9\7\60\2\2\u00b8\u00b7\3\2"+
		"\2\2\u00b8\u00b9\3\2\2\2\u00b9\u00c0\3\2\2\2\u00ba\u00bc\5A!\2\u00bb\u00ba"+
		"\3\2\2\2\u00bb\u00bc\3\2\2\2\u00bc\u00bd\3\2\2\2\u00bd\u00be\7\60\2\2"+
		"\u00be\u00c0\5A!\2\u00bf\u00b6\3\2\2\2\u00bf\u00bb\3\2\2\2\u00c0\u00c1"+
		"\3\2\2\2\u00c1\u00c3\t\r\2\2\u00c2\u00c4\t\16\2\2\u00c3\u00c2\3\2\2\2"+
		"\u00c3\u00c4\3\2\2\2\u00c4\u00c5\3\2\2\2\u00c5\u00c6\5E#\2\u00c6\32\3"+
		"\2\2\2\u00c7\u00c8\7v\2\2\u00c8\u00c9\7t\2\2\u00c9\u00ca\7w\2\2\u00ca"+
		"\u00d1\7g\2\2\u00cb\u00cc\7h\2\2\u00cc\u00cd\7c\2\2\u00cd\u00ce\7n\2\2"+
		"\u00ce\u00cf\7u\2\2\u00cf\u00d1\7g\2\2\u00d0\u00c7\3\2\2\2\u00d0\u00cb"+
		"\3\2\2\2\u00d1\34\3\2\2\2\u00d2\u00d5\7)\2\2\u00d3\u00d6\n\17\2\2\u00d4"+
		"\u00d6\5=\37\2\u00d5\u00d3\3\2\2\2\u00d5\u00d4\3\2\2\2\u00d6\u00d7\3\2"+
		"\2\2\u00d7\u00d8\7)\2\2\u00d8\36\3\2\2\2\u00d9\u00dc\7$\2\2\u00da\u00dd"+
		"\n\20\2\2\u00db\u00dd\5=\37\2\u00dc\u00da\3\2\2\2\u00dc\u00db\3\2\2\2"+
		"\u00dd\u00de\3\2\2\2\u00de\u00df\7$\2\2\u00df \3\2\2\2\u00e0\u00e1\7*"+
		"\2\2\u00e1\"\3\2\2\2\u00e2\u00e3\7+\2\2\u00e3$\3\2\2\2\u00e4\u00e5\7}"+
		"\2\2\u00e5&\3\2\2\2\u00e6\u00e7\7\177\2\2\u00e7(\3\2\2\2\u00e8\u00e9\7"+
		"]\2\2\u00e9*\3\2\2\2\u00ea\u00eb\7_\2\2\u00eb,\3\2\2\2\u00ec\u00ed\7="+
		"\2\2\u00ed.\3\2\2\2\u00ee\u00ef\7.\2\2\u00ef\60\3\2\2\2\u00f0\u00f1\7"+
		"\60\2\2\u00f1\62\3\2\2\2\u00f2\u00f3\7?\2\2\u00f3\64\3\2\2\2\u00f4\u00f8"+
		"\5I%\2\u00f5\u00f7\5G$\2\u00f6\u00f5\3\2\2\2\u00f7\u00fa\3\2\2\2\u00f8"+
		"\u00f6\3\2\2\2\u00f8\u00f9\3\2\2\2\u00f9\66\3\2\2\2\u00fa\u00f8\3\2\2"+
		"\2\u00fb\u00fd\t\21\2\2\u00fc\u00fb\3\2\2\2\u00fd\u00fe\3\2\2\2\u00fe"+
		"\u00fc\3\2\2\2\u00fe\u00ff\3\2\2\2\u00ff\u0100\3\2\2\2\u0100\u0101\b\34"+
		"\2\2\u01018\3\2\2\2\u0102\u0106\7%\2\2\u0103\u0105\n\22\2\2\u0104\u0103"+
		"\3\2\2\2\u0105\u0108\3\2\2\2\u0106\u0104\3\2\2\2\u0106\u0107\3\2\2\2\u0107"+
		"\u0109\3\2\2\2\u0108\u0106\3\2\2\2\u0109\u010a\b\35\2\2\u010a:\3\2\2\2"+
		"\u010b\u010c\7%\2\2\u010c\u010d\7%\2\2\u010d\u0111\3\2\2\2\u010e\u0110"+
		"\13\2\2\2\u010f\u010e\3\2\2\2\u0110\u0113\3\2\2\2\u0111\u0112\3\2\2\2"+
		"\u0111\u010f\3\2\2\2\u0112\u0114\3\2\2\2\u0113\u0111\3\2\2\2\u0114\u0115"+
		"\7%\2\2\u0115\u0116\7%\2\2\u0116\u0117\3\2\2\2\u0117\u0118\b\36\2\2\u0118"+
		"<\3\2\2\2\u0119\u011a\7^\2\2\u011a\u012f\t\23\2\2\u011b\u0120\7^\2\2\u011c"+
		"\u011e\t\24\2\2\u011d\u011c\3\2\2\2\u011d\u011e\3\2\2\2\u011e\u011f\3"+
		"\2\2\2\u011f\u0121\t\7\2\2\u0120\u011d\3\2\2\2\u0120\u0121\3\2\2\2\u0121"+
		"\u0122\3\2\2\2\u0122\u012f\t\7\2\2\u0123\u0125\7^\2\2\u0124\u0126\7w\2"+
		"\2\u0125\u0124\3\2\2\2\u0126\u0127\3\2\2\2\u0127\u0125\3\2\2\2\u0127\u0128"+
		"\3\2\2\2\u0128\u0129\3\2\2\2\u0129\u012a\5C\"\2\u012a\u012b\5C\"\2\u012b"+
		"\u012c\5C\"\2\u012c\u012d\5C\"\2\u012d\u012f\3\2\2\2\u012e\u0119\3\2\2"+
		"\2\u012e\u011b\3\2\2\2\u012e\u0123\3\2\2\2\u012f>\3\2\2\2\u0130\u0132"+
		"\t\25\2\2\u0131\u0133\t\16\2\2\u0132\u0131\3\2\2\2\u0132\u0133\3\2\2\2"+
		"\u0133\u0134\3\2\2\2\u0134\u0135\5E#\2\u0135@\3\2\2\2\u0136\u013f\5C\""+
		"\2\u0137\u013a\5C\"\2\u0138\u013a\7a\2\2\u0139\u0137\3\2\2\2\u0139\u0138"+
		"\3\2\2\2\u013a\u013d\3\2\2\2\u013b\u0139\3\2\2\2\u013b\u013c\3\2\2\2\u013c"+
		"\u013e\3\2\2\2\u013d\u013b\3\2\2\2\u013e\u0140\5C\"\2\u013f\u013b\3\2"+
		"\2\2\u013f\u0140\3\2\2\2\u0140B\3\2\2\2\u0141\u0142\t\4\2\2\u0142D\3\2"+
		"\2\2\u0143\u014b\t\26\2\2\u0144\u0146\t\27\2\2\u0145\u0144\3\2\2\2\u0146"+
		"\u0149\3\2\2\2\u0147\u0145\3\2\2\2\u0147\u0148\3\2\2\2\u0148\u014a\3\2"+
		"\2\2\u0149\u0147\3\2\2\2\u014a\u014c\t\26\2\2\u014b\u0147\3\2\2\2\u014b"+
		"\u014c\3\2\2\2\u014cF\3\2\2\2\u014d\u0150\5I%\2\u014e\u0150\t\26\2\2\u014f"+
		"\u014d\3\2\2\2\u014f\u014e\3\2\2\2\u0150H\3\2\2\2\u0151\u0152\t\30\2\2"+
		"\u0152J\3\2\2\2)\2jort|\u0080\u0087\u008e\u0092\u009a\u009e\u00a1\u00a6"+
		"\u00aa\u00ad\u00b2\u00b8\u00bb\u00bf\u00c3\u00d0\u00d5\u00dc\u00f8\u00fe"+
		"\u0106\u0111\u011d\u0120\u0127\u012e\u0132\u0139\u013b\u013f\u0147\u014b"+
		"\u014f\3\2\3\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}