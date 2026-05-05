// / execution-charset:UTF-8

import std;
using namespace std;
// format-spec:
//   std-format-spec(*)
//   range-format-spec(*)
//   tuple-format-spec(*)
//   path-format-spec/thread-id-format-spec/stacktrace-entry-format-spec(*)
//   chrono-format-spec
//   user-defined formatter specializations

auto main() -> int {
    using namespace chrono;
    locale::global(locale("ko_KR"));

    auto utc_now = system_clock::now();
    auto now = zoned_time{ current_zone(), utc_now };

    // chrono-format-spec:
    //      [[fill]align][width][precision][L][chrono-specs]
    // 
    // [[fill]align]:
    //      채움문자
    //          single unicode scalar value: utf-8 code unit:1~4
    //          field width를 1로 계산
    //          올수 없는 문자 { }
    //      정렬(< ^ >)
    // 
    // [width]: 
    //      minimum field width
    //      dynamic width
    // 
    // [.precision]: 
    //      정밀도
    //      [chrono::duration] floating-point representation type
    //      dynamic precision 

    // Some of the conversion specifiers depend on the formatting locale.
    // If 
    //  the string literal encoding is a Unicode encoding form and 
    //  the locale is among an implementation-defined set of locales, 
    // each replacement that depends on the locale 
    // is performed as if the replacement character sequence is converted to the string literal encoding.
    // [L]: 
    //     L 옵션 없음: "C" locale 사용
    //     L 옵션만 사용: global locale 사용
    //     L 옵션 + locale 객체: 전달된 locale 사용
    //     [locale]
    // 
    // chrono-specs:
    //    conversion-spec
    //    chrono-specs conversion-spec
    //    chrono-specs literal-char
    // 
    // iteral-char:
    //      any character other than { } %
    // 
    // conversion-spec:
    //      %[modifier]type
    //      conversion-spec에 대한 대응 information를 갖고 있는 format-arg.
    // 
    // modifier:
    //      E O

    println("|{0:%t literal text %% %n new line}|", now);
    // type:      
    //      t               : tab
    //      %               : % character
    //      n               : A new-line character.

    println(" %y:{0:%y} L%Oy:{0:L%Oy} L%Ey:{0:L%Ey}", now);
    println(" %Y:{0:%Y} L%EY:{0:L%EY}", now);
    println(" %C:{0:%C} L%EC:{0:L%EC}", now);
    println(" %G:{0:%G}", now);
    println(" %g:{0:%g}", now);
    // type: year
    //      y               : last two decimal digits of the year.
    //                          0를 사용한 2자리 
    //                          %Oy [locale]
    //                          %Ey [locale] alternative representation of offset from %EC(year only)
    //      Y               : year as a decimal number.
    //                          0를 사용한 4자리
    //                          %EY [locale]
    //      C               : floor(year/100)
    //                          0를 사용한 2자리
    //                          %EC [locale]
    //      G               : calendar year as a decimal number for week calendar.
    //                          0를 사용한 4자리   
    //      g               : last two decimal digits of the calendar year for week calendar.
    //                          0를 사용한 2자리 

    println("L%b:{0:L%b} L%B:{0:L%B}", now);
    println("L%h:{0:L%h}", now);
    println(" %m:{0:%m}", now);
    // type: month name/month number
    //      b B             : [locale] month name abbreviated/full 
    //      h               : %b
    //      m               : month as a decimal number. Jan is 01
    //                          0를 사용한 2자리


    println("L%a:{0:L%a} L%A:{0:L%A}", now);
    println("%a:{0:%a} %A:{0:%A}", now);
    println("%w:{0:%w} L%Ow:{0:L%Ow}", now);
    println("%u:{0:%u} L%Ou:{0:L%Ou}", now);
    // type: weekday name/weekday/calendar weekday 
    //      a A             : [locale]weekday name abbreviated/full 
    //      w               : weekday as a decimal number (0-6), Sunday is 0.
    //                          %Ow [locale]
    //      u               : calendar day of week as a decimal number (1-7). Monday is 1
    //                          %Ou [locale]

    println("%W:{0:%W} L%OW:{0:L%OW}", now);
    println("%U:{0:%U} L%OU:{0:L%OU}", now);
    println("%V:{0:%V} L%OV:{0:L%OV}", now);
    // type: week number/ calendar week number
    //      W               : week number of the year as a decimal number.
    //                          The first Monday of the year is the first day of week 01.
    //                          Days of the same year prior to that are in week 00.
    //                          0를 사용한 2자리
    //                          %OW [locale]
    //      U               : week number of the year as a decimal number. 
    //                          The first Sunday of the year is the first day of week 01.
    //                          Days of the same year prior to that are in week 00.
    //                          0를 사용한 2자리
    //                          %OU [locale]
    //      V               : calendar week of year as a decimal number for the week calendar.
    //                          0를 사용한 2자리
    //                          %OV [locale]


    auto duration1 = 24h * 60 + 25min + 7s;
    println("%d:{0:%d} L%Od:{0:L%Od}", now);
    println("%e:{0:%e} L%Od:{0:L%Oe}", now);
    println("%j:{:%j} %j:{:%j}", now, duration1);
    // type: day
    //      d               : day of month as a decimal number. 
    //                          0를 사용한 2자리
    //                          %Od [locale]
    //      e               : day of month as a decimal number. 
    //                          space를 사용한 2자리
    //                          %Oe [locale]
    //      j               : if specialization of duration,
    //                           decimal number of days without padding.
    //                        Otherwise
    //                          day of the year as a decimal number.
    //                          ex) January 1 -> 001
    //                          0를 사용한 3자리


    println(" %T:{0:%T}", now);
    println(" %R:{0:%R}", now);
    println(" %H:{0:%H} L%OH:{0:L%OH}", now);
    println(" %I:{0:%I} L%OI:{0:L%OI}", now);
    println(" L%r:{0:L%r}", now);
    println(" L%p:{0:L%p}", now);
    println(" %M:{0:%M} L%OM:{0:L%OM}", now);
    println(" %S:{0:%S} L%OS:{0:L%OS}", now);
    // type: time 
    //      T               : %H:%M:%S
    //      R               : %H:%M
    //      H               : hour (24-hour clock) as a decimal number.
    //                          0를 사용한 2자리
    //                          %OH [locale]
    //      I               : hour (12-hour clock) as a decimal number.
    //                          0를 사용한 2자리
    //                          %OI [locale]    
    //      r               : [locale] 12-hour clock time.
    //      p               : [locale] equivalent of the AM/PM designations(12-hour clock).
    //      M               : minute as a decimal number. 
    //                          0를 사용한 2자리
    //                          %OM [locale] 
    //      S               : Seconds as a decimal number. 
    //                          0를 사용한 2자리
    //                        if input cannot exactly represented with seconds,
    //                          decimal floating-point number with a fixed format 
    //                          and a precision matching that of the precision of the input
    //                          (or to a microseconds precision if the conversion to floating-point 
    //                          decimal seconds cannot be made within 18 fractional digits)
    //                          The character for the decimal point is localized according to the locale.
    //                          %OS [locale] 


    println(" L%c:{0:L%c} L%Ec:{0:L%Ec}", now);
    println(" L%x:{0:L%x} L%Ex:{0:L%Ex}", now);
    println(" L%X:{0:L%X} L%EX:{0:L%EX}", now);
    println("%F:{0:%F}", now);
    println("%D:{0:%D}", now);
    // type: date and time 
    //      c               : [locale] date and time
    //                          %Ec [locale]
    //      x               : [locale] date representation. 
    //                          %Ex [locale]
    //      X               : [locale] time representation. 
    //                          %EX [locale]    
    //      F               : %Y-%m-%d   
    //      D               : %m/%d/%y     


    // The result of formatting a std::chrono::duration instance holding a negative value, 
    // or an hh_mm_ss object h for which h.is_negative() is true, 
    // is equivalent to the output of the corresponding positive value,
    // with a STATICALLY-WIDEN<charT>("-") character sequence placed before 
    // the replacement of the initial conversion specifier
    seconds se{ -10'000s };
    hh_mm_ss hms{ se };
    println("{:%T} {:%T}", se, hms);
    println("{:%H:%M:%S} {:%H:%M:%S}", se, hms);
    println("minutes {:%M, hours %H, seconds %S}", se);
    println("minutes {:%M, hours %H, seconds %S}", hms);

    auto duration2 = 10'320ns;
    println("%q:{0:%q}", duration2);
    println("%Q:{0:%Q}", duration2);
    println("%Q%q:{0:%Q%q}", duration2);
    // type: duration 
    //      q               : The duration’s unit suffix.
    //      Q               : The duration’s numeric value  


    auto los_now = chrono::zoned_time{ "America/Los_Angeles", now };
    println("{0} %z:{0:%z} %Ez:{0:%Ez} %Oz:{0:%Oz}", los_now);
    println("%Z:{0:%Z}", los_now);
    // type: time zone/offset 
    //      z               : offset from UTC.
    //                          -0430 refers to 4 hours 30 minutes behind UTC.
    //                          %Ez %Oz(: between the hours and minutes: -04:30)
    //      Z               : time zone abbreviation.
    return 0;
}