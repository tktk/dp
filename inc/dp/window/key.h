#ifndef DP_WINDOW_KEY_H
#define DP_WINDOW_KEY_H

namespace dp {
    enum Key
    {
        INVALID,

        SPACE = 0x20,

        EXCLAMATION,    // !
        DOUBLE_QUOTES,  // "
        NUMBER_SIGN,    // #
        DOLLAR, // $
        PARCENT,    // %
        AMPERSAND,  // &
        APOSTROPHE, // '
        PAREN_LEFT, // (
        PAREN_RIGHT,    // )
        ASTERISK,   // *
        PLUS,   // +
        COMMA,  // ,
        MINUS,  // -
        PERIOD, // .
        SLASH,  // /

        _0,
        _1,
        _2,
        _3,
        _4,
        _5,
        _6,
        _7,
        _8,
        _9,

        COLON,  // :
        SEMICOLON,  // ;
        LESS,   // <
        EQUAL,  // =
        GREATER,    // >
        QUESTION,   // ?
        AT, // @

        A,
        B,
        C,
        D,
        E,
        F,
        G,
        H,
        I,
        J,
        K,
        L,
        M,
        N,
        O,
        P,
        Q,
        R,
        S,
        T,
        U,
        V,
        W,
        X,
        Y,
        Z,

        BRACKET_LEFT,   // [
        BACK_SLASH, // ＼

        BRACKET_RIGHT,  // ]
        CIRCUM_FLEX,    // ^
        UNDER_SCORE,    // _
        GRAVE,  // `

        a,
        b,
        c,
        d,
        e,
        f,
        g,
        h,
        i,
        j,
        k,
        l,
        m,
        n,
        o,
        p,
        q,
        r,
        s,
        t,
        u,
        v,
        w,
        x,
        y,
        z,

        BRACE_LEFT, // {
        VERTICAL_BAR,   // |
        BRACE_RIGHT,    // }
        TILDE,  // ~

        // テンキー
        KP_SPACE = 0x1000,

        KP_EQUAL,   // =
        KP_ASTERISK,    // *
        KP_PLUS,    // +
        KP_COMMA,   // ,
        KP_MINUS,   // -
        KP_PERIOD,  // .
        KP_SLASH,   // /

        KP_0,
        KP_1,
        KP_2,
        KP_3,
        KP_4,
        KP_5,
        KP_6,
        KP_7,
        KP_8,
        KP_9,

        // 特殊キー
        LEFT = 0x2000,
        UP,
        RIGHT,
        DOWN,

        PAGE_UP,
        PAGE_DOWN,

        HOME,
        END,

        SHIFT_LEFT,
        SHIFT_RIGHT,

        CONTROL_LEFT,
        CONTROL_RIGHT,

        ALT_LEFT,
        ALT_RIGHT,

        SUPER_LEFT,
        SUPER_RIGHT,

        BACK_SPACE,
        TAB,
        ENTER,
        ESCAPE,
        DELETE,
        INSERT,
        BREAK,
        CAPS_LOCK,
        NUM_LOCK,
        SCROLL_LOCK,
        PRINT_SCREEN,
        PAUSE,
        APPLICATION,
        BEGIN,
        EISU,   // 英数
        MUHENKAN,   // 無変換
        HENKAN, // 変換
        HIRAGANA_KATAKANA,  // ひらがな/カタカナ
        ZENKAKU_HANKAKU,    // 全角/半角

        // テンキーの特殊キー
        KP_LEFT = 0x3000,
        KP_UP,
        KP_RIGHT,
        KP_DOWN,

        KP_PAGE_UP,
        KP_PAGE_DOWN,

        KP_HOME,
        KP_END,

        KP_TAB,
        KP_ENTER,
        KP_DELETE,
        KP_INSERT,
        KP_BEGIN,

        // ファンクションキー
        F1 = 0x4000,
        F2,
        F3,
        F4,
        F5,
        F6,
        F7,
        F8,
        F9,
        F10,
        F11,
        F12,
    };
}

#endif  // DP_WINDOW_KEY_H
